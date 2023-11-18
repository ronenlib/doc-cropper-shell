#include "BasicOperation.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"
#include <string>
#include <vector>

using namespace std;

#ifndef DOC_CROPPER_CONTOUR_DETECT_H
#define DOC_CROPPER_CONTOUR_DETECT_H

class ContourDetect : public BasicOperation
{
private:
  const Image &image;
  vector<vector<Point>> contours;

public:
  ContourDetect(DetectEdges &operation, const Image &image);
  void display() override;
  void apply() override;
};

#endif