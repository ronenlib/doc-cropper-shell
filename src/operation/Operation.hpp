#include "../Displayable.hpp"

#ifndef DOC_CROPPER_OPERATION_H
#define DOC_CROPPER_OPERATION_H

class Operation : public Displayable
{
public:
    virtual void apply() = 0;
};

#endif