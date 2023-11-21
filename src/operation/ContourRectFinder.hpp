#include "../types.hpp"
#include "../Renderer.hpp"
#include "BasicOperation.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"

#ifndef DOC_CROPPER_CONTOUR_RECT_FINDER_H
#define DOC_CROPPER_CONTOUR_RECT_FINDER_H

class ContourRectFinder : public BasicOperation
{
protected:
  const Image &image;
  bool isRectFound;
  VectorVectorPoint contours;
  VectorPoint rect;

  void findAllContours();
  bool findRectContour();

public:
  ContourRectFinder(DetectEdges &operation, const Image &image);
  void apply() override;
  void display(Renderer &renderer) override;
  bool getIsRectFound();
  VectorPoint& getRect();
};

#endif