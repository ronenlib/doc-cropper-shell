#include "BasicOperation.hpp"
#include "../types.hpp"
#include "../Image.hpp"

#ifndef DOC_CROPPER_IMAGE_OPERATION_H
#define DOC_CROPPER_IMAGE_OPERATION_H

class ImageOperation : public Operation
{
private:
  static const string NAME;
  const Image &image;
public:
  ImageOperation(const Image &image);
  void apply() override;
  const string &getDisplayableName() const override;
};

#endif