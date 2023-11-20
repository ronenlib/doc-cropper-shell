
#include "DetectEdges.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#define THRESHOLD_VAL 150
#define MAX_VAL 255

DetectEdges::DetectEdges(Operation &operation) : BasicOperation("DetectEdges", operation) {}

void DetectEdges::apply()
{
  this->operation.apply();

  const DisplayData &source = this->operation.getDisplayableData();

  threshold(source, this->data, THRESHOLD_VAL, MAX_VAL, cv::THRESH_BINARY);
}