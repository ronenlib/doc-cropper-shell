#include <opencv2/core.hpp>
#include <string>
#include <vector>

#ifndef DOC_CROPPER_TYPES_H
#define DOC_CROPPER_TYPES_H

typedef cv::Mat DisplayData;
typedef cv::Point2f FloatPoint;
typedef cv::Point Point;

typedef std::string string;
typedef std::vector<Point> VectorPoint;
typedef std::vector<Point *> VectorPtrPoint;
typedef std::vector<FloatPoint> VectorFloatPoint;
typedef std::vector<VectorPoint> VectorVectorPoint;

#endif
