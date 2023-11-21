#include "../types.hpp"
#include "../Image.hpp"
#include "../Renderer.hpp"
#include "ContourRectFinder.hpp"
#include "DetectEdges.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <limits.h>

ContourRectFinder::ContourRectFinder(DetectEdges &operation, const Image &image)
    : BasicOperation("ContourRectFinder", operation), image{image}, isRectFound{false}
{
  this->data = image.getDisplayableData();
}

void ContourRectFinder::apply()
{
  this->operation.apply();

  this->findAllContours();

  this->isRectFound = this->findRectContour();
}

void ContourRectFinder::display(Renderer &renderer)
{
  if (!this->isRectFound)
  {
    std::cout << "No rect contour found, displaying original image" << std::endl;

    this->operation.display(renderer);

    return;
  }

  const DisplayData &data = this->image.getDisplayableData().clone();

  cv::drawContours(data, this->contours, -1, cv::Scalar(255, 0, 0), 3);

  cv::drawContours(data, VectorVectorPoint({this->rect}), -1, cv::Scalar(0, 255, 0), 5);

  renderer.render(this->opName, data);
}

void ContourRectFinder::findAllContours()
{
  const DisplayData &source = this->operation.getDisplayableData();

  findContours(source, this->contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
}

bool ContourRectFinder::findRectContour()
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

bool ContourRectFinder::getIsRectFound()
{
  return this->isRectFound;
}

VectorPoint &ContourRectFinder::getRect()
{
  return this->rect;
}
