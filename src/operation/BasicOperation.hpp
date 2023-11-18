#include "Operation.hpp"
#include <string>

using namespace std;

#ifndef DOC_CROPPER_BASIC_OPERATION_H
#define DOC_CROPPER_BASIC_OPERATION_H

class BasicOperation : public Operation
{
protected:
    const string opName;
    Operation &operation;

public:
    BasicOperation(const string &opName, Operation &operation);
    const string &getDisplayableName() const override;
};

#endif