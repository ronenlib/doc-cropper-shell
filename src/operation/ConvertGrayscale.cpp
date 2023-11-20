
#include "ConvertGrayscale.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

ConvertGrayscale::ConvertGrayscale(Operation &operation)
    : BasicOperation("ConvertGrayscale", operation){}

void ConvertGrayscale::apply()
{
  this->operation.apply();

  const DisplayData &source = this->operation.getDisplayableData();

  cvtColor(source, this->data, cv::COLOR_BGR2GRAY);
}