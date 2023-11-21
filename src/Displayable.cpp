#include "types.hpp"
#include "Displayable.hpp"
#include "Renderer.hpp"
#include <opencv2/core.hpp>
#include <string>

void Displayable::display(Renderer &renderer)
{
    const string &name = this->getDisplayableName();

    renderer.render(name, this->data);
}

const DisplayData &Displayable::getDisplayableData() const
{
    return this->data;
}
