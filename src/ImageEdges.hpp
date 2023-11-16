#include <string>
#include <opencv2/core.hpp>
#include "Image.hpp"

#ifndef DOC_CROPPER_IMAGE_EDGES_H
#define DOC_CROPPER_IMAGE_EDGES_H

class ImageEdges : public Image
{
private:
    void detectEdges(const cv::Mat &source);

public:
    ImageEdges(const std::string &name, const std::string &imgPath);
    ImageEdges(const std::string &name, const Image &origin);
};

#endif