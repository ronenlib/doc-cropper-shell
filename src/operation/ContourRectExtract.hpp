#include "BasicOperation.hpp"
#include "DetectEdges.hpp"
#include "../Image.hpp"
#include <string>
#include <vector>

using namespace std;

#ifndef DOC_CROPPER_CONTOUR_RECT_EXTRACT_H
#define DOC_CROPPER_CONTOUR_RECT_EXTRACT_H

class ContourRectExtract : public BasicOperation
{
private:
  const Image &image;
  vector<vector<Point>> contours;
  vector<Point> rect;

  void extractAllContours();
  bool findDocContour();
  void rearrangeRectPoint(vector<Point2f> &rearrangedPoints);
  void extractDocContour(vector<Point2f> &points);
  double euclideanDist(Point2f &p1, Point2f &p2);

public:
  ContourRectExtract(DetectEdges &operation, const Image &image);
  void apply() override;
};

#endif