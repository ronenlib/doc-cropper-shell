#include "types.hpp"
#include <opencv2/core.hpp>
#include <string>

#ifndef DOC_CROPPER_DISPLAYABLE_H
#define DOC_CROPPER_DISPLAYABLE_H

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