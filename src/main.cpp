#include <iostream>
#include "Image.hpp"
#include "ImageEdges.hpp"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "input file is required" << std::endl;
    std::cerr << "usage: doc-cropper <input_file>" << std::endl;

    return -1;
  }

  Image img("original", argv[1]);

  img.display(false);

  ImageEdges edges("edges", img);

  edges.display(true);

  return 0;
}