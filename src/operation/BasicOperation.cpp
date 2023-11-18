#include "../Displayable.hpp"
#include "BasicOperation.hpp"
#include <string>

using namespace std;

BasicOperation::BasicOperation(const string &opName, Operation &operation)
    : opName{opName}, operation{operation} {}

const string &BasicOperation::getDisplayableName() const
{
  return this->opName;
}