
#include "DetectEdges.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#define CANNY_THRESHOLD_1 75
#define CANNY_THRESHOLD_2 200

using namespace cv;

DetectEdges::DetectEdges(Operation &operation) : BasicOperation("DetectEdges", operation) {}

void DetectEdges::apply()
{
  this->operation.apply();

  const DisplayData &source = this->operation.getDisplayableData();

  Canny(source, this->data, CANNY_THRESHOLD_1, CANNY_THRESHOLD_2);
}