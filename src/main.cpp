#include "Image.hpp"
#include "operation/ImageOperation.hpp"
#include "operation/ConvertGrayscale.hpp"
#include "operation/Blur.hpp"
#include "operation/DetectEdges.hpp"
#include "operation/ContourDetect.hpp"
#include <iostream>
#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "input file is required" << std::endl;
    std::cerr << "usage: doc-cropper <input_file>" << std::endl;

    return -1;
  }

  Image img("original", argv[1]);
  
  ImageOperation base(img);
  ConvertGrayscale gray(base);
  Blur blur(gray);
  DetectEdges edges(blur);
  ContourDetect contours(edges, img);
  // EdgeDetection edgeDetection("edge", img.getDisplayableData());

  edges.apply();
  edges.display();

  cv::waitKey(0);

  return 0;
}