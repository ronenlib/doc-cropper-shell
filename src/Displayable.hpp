#include <opencv2/core.hpp>
#include <string>

using namespace std;

#ifndef DOC_CROPPER_DISPLAYABLE_H
#define DOC_CROPPER_DISPLAYABLE_H

typedef cv::Mat DisplayData;

class Displayable
{
protected:
    DisplayData data;

public:
    virtual void display();
    const DisplayData &getDisplayableData() const;
    virtual const string &getDisplayableName() const = 0;
};

#endif