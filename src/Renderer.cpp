#include "Renderer.hpp"
#include <opencv2/highgui.hpp>

Renderer::Renderer() {}

void Renderer::render(const string &name, const DisplayData &data)
{
  cv::namedWindow(name, cv::WINDOW_NORMAL);
  cv::resizeWindow(name, 500, 500);
  cv::imshow(name, data);

  cv::waitKey(0);

  cv::destroyWindow(name);
}