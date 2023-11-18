
#include "Blur.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#define GAUSSIAN_BLUR_SIZE 5

using namespace cv;

Blur::Blur(Operation &operation) : BasicOperation("Blur", operation) {}

void Blur::apply()
{
  this->operation.apply();

  Size2i size(GAUSSIAN_BLUR_SIZE, GAUSSIAN_BLUR_SIZE);

  const DisplayData &source = this->operation.getDisplayableData();

  GaussianBlur(source, this->data, size, 0);
}