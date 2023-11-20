
#include "ContourRectExtract.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <limits.h>

using namespace cv;

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

  vector<Point2f> rearrangedPoints;

  this->rearrangeRectPoint(rearrangedPoints);
  this->extractDocContour(rearrangedPoints);
}

void ContourRectExtract::extractAllContours()
{
  const DisplayData &edgeData = this->operation.getDisplayableData();

  findContours(edgeData, this->contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
}

bool ContourRectExtract::findDocContour()
{
  int maxLen = 0;

  for (auto it = this->contours.begin(); it != this->contours.end(); ++it)
  {
    vector<Point> rect;

    int len = arcLength(*it, true);
    approxPolyDP(*it, rect, 0.02 * len, true);

    if (maxLen < len && rect.size() == 4)
    {
      maxLen = len;
      this->rect = rect;
    }
  }

  return maxLen != 0;
}

void ContourRectExtract::rearrangeRectPoint(vector<Point2f> &rearrangedPoints)
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

  vector<Point *> pointsRem;

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

  rearrangedPoints.push_back(Point2f(topLeft->x, topLeft->y));
  rearrangedPoints.push_back(Point2f(pointsRem[1]->x, pointsRem[1]->y));
  rearrangedPoints.push_back(Point2f(bottomRight->x, bottomRight->y));
  rearrangedPoints.push_back(Point2f(pointsRem[0]->x, pointsRem[0]->y));
}

void ContourRectExtract::extractDocContour(vector<Point2f> &points)
{
  double width = this->euclideanDist(points[0], points[1]);
  double height = this->euclideanDist(points[0], points[3]);

  vector<Point2f> dst({
      Point2f(0, 0),
      Point2f(width, 0),
      Point2f(width, height),
      Point2f(0, height),
  });

  this->data = getPerspectiveTransform(points, dst);

  const DisplayData &source = this->image.getDisplayableData();

  warpPerspective(source, this->data, this->data, Size(width, height));
}

double ContourRectExtract::euclideanDist(Point2f &p1, Point2f &p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}