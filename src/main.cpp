#include "Image.hpp"
#include "Renderer.hpp"
#include "operation/ImageOperation.hpp"
#include "operation/ConvertGrayscale.hpp"
#include "operation/Blur.hpp"
#include "operation/DetectEdges.hpp"
#include "operation/ContourRectFinder.hpp"
#include "operation/ContourRectCrop.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "input file is required" << std::endl;
    std::cerr << "usage: doc-cropper <input_file>" << std::endl;

    return -1;
  }

  Renderer renderer;

  Image img("original", argv[1]);
  
  ImageOperation base(img);
  ConvertGrayscale gray(base);
  Blur blur(gray);
  DetectEdges edges(blur);
  ContourRectFinder rectFinder(edges, img);
  ContourRectCrop rect(rectFinder);

  rect.apply();
  rect.display(renderer);

  return 0;
}