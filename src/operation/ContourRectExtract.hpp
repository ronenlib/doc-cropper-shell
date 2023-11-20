#include "../types.hpp"
#include "BasicOperation.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"

#ifndef DOC_CROPPER_CONTOUR_RECT_EXTRACT_H
#define DOC_CROPPER_CONTOUR_RECT_EXTRACT_H

class ContourRectExtract : public BasicOperation
{
private:
  const Image &image;
  VectorVectorPoint contours;
  VectorPoint rect;

  void extractAllContours();
  bool findDocContour();
  void rearrangeRectPoint(VectorFloatPoint &rearrangedPoints);
  void extractDocContour(VectorFloatPoint &points);
  double euclideanDist(FloatPoint &p1, FloatPoint &p2);

public:
  ContourRectExtract(DetectEdges &operation, const Image &image);
  void apply() override;
};

#endif