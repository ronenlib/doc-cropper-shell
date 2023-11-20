#include "../types.hpp"
#include "BasicOperation.hpp"

#ifndef DOC_CROPPER_BLUR_H
#define DOC_CROPPER_BLUR_H

class Blur : public BasicOperation
{
public:
  Blur(Operation &operation);
  void apply() override;
};

#endif