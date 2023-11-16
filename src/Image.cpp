#include <string>
#include "opencv2/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "Image.hpp"

#define WIN_SIZE 500
#define DEFAULT_NAME "blank"

Image::Image() : name{DEFAULT_NAME}
{
  this->data = cv::Mat{};
}

Image::Image(const std::string &name) : name{name}
{
  this->data = cv::Mat{};
}

Image::Image(const std::string &name, const std::string &imgPath) : name{name}
{
  this->data = cv::imread(imgPath);
}

void Image::display(bool isBlocking)
{
  cv::namedWindow(name, cv::WINDOW_NORMAL);
  cv::resizeWindow(name, WIN_SIZE, WIN_SIZE);
  cv::imshow(name, this->data);

  if (isBlocking)
  {
    cv::waitKey(0);
  }
}

const cv::Mat &Image::getData() const
{
  return this->data;
}