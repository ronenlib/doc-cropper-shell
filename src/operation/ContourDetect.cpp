
#include "ContourDetect.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

ContourDetect::ContourDetect(DetectEdges &operation, const Image &image) 
: BasicOperation("ContourDetect", operation), image {image} {
  this->data = image.getDisplayableData().clone();
}

void ContourDetect::display() {
  Scalar color(0, 255, 0);
  drawContours(this->data, this->contours, -1, color, 8);

  BasicOperation::display();
}

void ContourDetect::apply()
{
  this->operation.apply();

  const DisplayData &edgeData = this->operation.getDisplayableData();

  findContours(edgeData, this->contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
}