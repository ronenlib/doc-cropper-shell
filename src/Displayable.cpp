#include "types.hpp"
#include "Displayable.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>

#define WIN_SIZE 500

void Displayable::display()
{
    const string &name = this->getDisplayableName();

    cv::namedWindow(name, cv::WINDOW_NORMAL);
    cv::resizeWindow(name, WIN_SIZE, WIN_SIZE);
    cv::imshow(name, this->data);
}

const DisplayData &Displayable::getDisplayableData() const
{
    return this->data;
}
