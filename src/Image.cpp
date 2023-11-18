#include "Image.hpp"
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

#define DEFAULT_NAME "blank"

Image::Image() : name{DEFAULT_NAME}
{
  this->data = Mat{};
}

Image::Image(const string &name) : name{name}
{
  this->data = Mat{};
}

Image::Image(const string &name, const string &imgPath) : name{name}
{
  this->data = imread(imgPath);
}

const string &Image::getDisplayableName() const
{
  return this->name;
}
