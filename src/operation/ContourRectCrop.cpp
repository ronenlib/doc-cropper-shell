#include "../types.hpp"
#include "ContourRectCrop.hpp"
#include "ContourRectFinder.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <limits.h>

ContourRectCrop::ContourRectCrop(ContourRectFinder &operation)
    : BasicOperation("ContourRectCrop", operation), operation{operation} {}

void ContourRectCrop::apply()
{
  this->operation.apply();

  if (!this->operation.getIsRectFound())
  {
    std::cout << "No document boundaries found, using full image" << std::endl;
    this->data = this->operation.getDisplayableData().clone();
    return;
  }

  VectorFloatPoint rearrangedPoints;

  this->rearrangeRectPoint(rearrangedPoints);
  this->extractDocContour(rearrangedPoints);
}

void ContourRectCrop::rearrangeRectPoint(VectorFloatPoint &rearrangedPoints)
{
  VectorPoint &rect = this->operation.getRect();
  Point *topLeft = &rect[0];
  Point *bottomRight = &rect[0];

  for (Point &point : rect)
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

  for (Point &point : rect)
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

void ContourRectCrop::extractDocContour(VectorFloatPoint &points)
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

  const DisplayData &source = this->operation.getDisplayableData();

  cv::warpPerspective(source, this->data, this->data, cv::Size(width, height));
}

double ContourRectCrop::euclideanDist(FloatPoint &p1, FloatPoint &p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}