#include "types.hpp"
#include "Image.hpp"
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#define DEFAULT_NAME "blank"

Image::Image() : name{DEFAULT_NAME}
{
  this->data = DisplayData{};
}

Image::Image(const string &name) : name{name}
{
  this->data = DisplayData{};
}

Image::Image(const string &name, const std::string &imgPath) : name{name}
{
  this->data = cv::imread(imgPath);
}

const string &Image::getDisplayableName() const
{
  return this->name;
}
