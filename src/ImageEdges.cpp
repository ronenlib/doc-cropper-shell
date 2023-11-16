#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageEdges.hpp"

#define GAUSSIAN_BLUR_SIZE 5
#define CANNY_THRESHOLD_1 75
#define CANNY_THRESHOLD_2 200

ImageEdges::ImageEdges(const std::string &name, const std::string &imgPath) : Image(name, imgPath)
{
  this->detectEdges(this->data);
}

ImageEdges::ImageEdges(const std::string &name, const Image &origin) : Image(name)
{
  const cv::Mat &source = origin.getData();

  this->detectEdges(source);
}

void ImageEdges::detectEdges(const cv::Mat &source)
{
  cv::cvtColor(source, this->data, cv::COLOR_BGR2GRAY);

  cv::Size2i size(GAUSSIAN_BLUR_SIZE, GAUSSIAN_BLUR_SIZE);

  cv::GaussianBlur(this->data, this->data, size, 0);

  cv::Canny(this->data, this->data, CANNY_THRESHOLD_1, CANNY_THRESHOLD_2);
}