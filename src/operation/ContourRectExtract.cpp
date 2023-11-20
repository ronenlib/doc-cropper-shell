#include "../types.hpp"
#include "ContourRectExtract.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <limits.h>

ContourRectExtract::ContourRectExtract(DetectEdges &operation, const Image &image)
    : BasicOperation("ContourRectExtract", operation), image{image} {}

void ContourRectExtract::apply()
{
  this->operation.apply();

  this->extractAllContours();

  bool isDocFound = this->findDocContour();

  if (!isDocFound)
  {
    std::cout << "No document boundaries found, using full image" << std::endl;
    this->data = this->image.getDisplayableData().clone();
    return;
  }

  VectorFloatPoint rearrangedPoints;

  this->rearrangeRectPoint(rearrangedPoints);
  this->extractDocContour(rearrangedPoints);
}

void ContourRectExtract::extractAllContours()
{
  const DisplayData &edgeData = this->operation.getDisplayableData();

  findContours(edgeData, this->contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
}

bool ContourRectExtract::findDocContour()
{
  int maxLen = 0;

  for (auto it = this->contours.begin(); it != this->contours.end(); ++it)
  {
    VectorPoint rect;

    int len = cv::arcLength(*it, true);
    cv::approxPolyDP(*it, rect, 0.02 * len, true);

    if (maxLen < len && rect.size() == 4)
    {
      maxLen = len;
      this->rect = rect;
    }
  }

  return maxLen != 0;
}

void ContourRectExtract::rearrangeRectPoint(VectorFloatPoint &rearrangedPoints)
{
  Point *topLeft = &this->rect[0];
  Point *bottomRight = &this->rect[0];

  for (Point &point : this->rect)
  {
    if (point.x + point.y > bottomRight->x + bottomRight->y)
    {
      bottomRight = &point;
    }

    if (point.x + point.y < topLeft->x + topLeft->y)
    {
      topLeft = &point;
    }
  }

  VectorPtrPoint pointsRem;

  for (Point &point : this->rect)
  {
    if (&point != topLeft && &point != bottomRight)
    {
      pointsRem.push_back(&point);
    }
  }

  if (pointsRem[0]->x > pointsRem[1]->x)
  {
    std::iter_swap(pointsRem.begin(), pointsRem.begin() + 1);
  }

  rearrangedPoints.push_back(FloatPoint(topLeft->x, topLeft->y));
  rearrangedPoints.push_back(FloatPoint(pointsRem[1]->x, pointsRem[1]->y));
  rearrangedPoints.push_back(FloatPoint(bottomRight->x, bottomRight->y));
  rearrangedPoints.push_back(FloatPoint(pointsRem[0]->x, pointsRem[0]->y));
}

void ContourRectExtract::extractDocContour(VectorFloatPoint &points)
{
  double width = this->euclideanDist(points[0], points[1]);
  double height = this->euclideanDist(points[0], points[3]);

  VectorFloatPoint dst({
      FloatPoint(0, 0),
      FloatPoint(width, 0),
      FloatPoint(width, height),
      FloatPoint(0, height),
  });

  this->data = cv::getPerspectiveTransform(points, dst);

  const DisplayData &source = this->image.getDisplayableData();

  cv::warpPerspective(source, this->data, this->data, cv::Size(width, height));
}

double ContourRectExtract::euclideanDist(FloatPoint &p1, FloatPoint &p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}