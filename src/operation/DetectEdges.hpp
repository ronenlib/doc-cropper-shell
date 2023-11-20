#include "BasicOperation.hpp"

#ifndef DOC_CROPPER_DETECT_EDGES_H
#define DOC_CROPPER_DETECT_EDGES_H

class DetectEdges : public BasicOperation
{
public:
  DetectEdges(Operation &operation);
  void apply() override;
};

#endif