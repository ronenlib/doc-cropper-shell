
#include "ConvertGrayscale.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

ConvertGrayscale::ConvertGrayscale(Operation &operation)
    : BasicOperation("ConvertGrayscale", operation){}

void ConvertGrayscale::apply()
{
  this->operation.apply();

  const DisplayData &source = this->operation.getDisplayableData();

  cvtColor(source, this->data, COLOR_BGR2GRAY);
}