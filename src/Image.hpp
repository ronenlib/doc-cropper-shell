#include "types.hpp"
#include "Displayable.hpp"
#include <string>
#include <opencv2/core.hpp>

#ifndef DOC_CROPPER_IMAGE_H
#define DOC_CROPPER_IMAGE_H

class Image : public Displayable
{
protected:
    const string name;

    Image();
    Image(const string &name);

public:
    Image(const string &name, const string &imgPath);
    const string &getDisplayableName() const override;
};

#endif