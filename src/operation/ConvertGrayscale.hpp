#include "BasicOperation.hpp"

#ifndef DOC_CROPPER_CONVERT_GRAYSCALE_H
#define DOC_CROPPER_CONVERT_GRAYSCALE_H

class ConvertGrayscale : public BasicOperation
{
public:
  ConvertGrayscale(Operation &operation);
  void apply() override;
};

#endif