
#include "ImageOperation.hpp"

const string ImageOperation::NAME = "Image";

ImageOperation::ImageOperation(const Image &image): image{image} {
  this->data = this->image.getDisplayableData();
}

void ImageOperation::apply() {}

const string &ImageOperation::getDisplayableName() const
{
  return this->NAME;
}