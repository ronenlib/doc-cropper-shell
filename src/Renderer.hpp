#include "types.hpp"

#ifndef DOC_CROPPER_RENDERER_H
#define DOC_CROPPER_RENDERER_H

class Renderer
{
public:
  Renderer();
  void render(const string &name, const DisplayData &data);
};

#endif