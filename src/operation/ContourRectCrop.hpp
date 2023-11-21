#include "../types.hpp"
#include "BasicOperation.hpp"
#include "ContourRectFinder.hpp"
#include "../Image.hpp"

#ifndef DOC_CROPPER_CONTOUR_RECT_CROP_H
#define DOC_CROPPER_CONTOUR_RECT_CROP_H

class ContourRectCrop : public BasicOperation
{
private:
  ContourRectFinder &operation;

  void rearrangeRectPoint(VectorFloatPoint &rearrangedPoints);
  void extractDocContour(VectorFloatPoint &points);
  double euclideanDist(FloatPoint &p1, FloatPoint &p2);

public:
  ContourRectCrop(ContourRectFinder &operation);
  void apply() override;
};

#endif