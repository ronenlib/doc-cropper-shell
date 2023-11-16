#include <string>
#include <opencv2/core.hpp>

#ifndef DOC_CROPPER_IMAGE_H
#define DOC_CROPPER_IMAGE_H

class Image
{
protected:
    const std::string name;
    cv::Mat data;

    Image();
    Image(const std::string &name);

public:
    Image(const std::string &name, const std::string &imgPath);

    void display(bool isBlocking);

    const cv::Mat &getData() const;
};

#endif