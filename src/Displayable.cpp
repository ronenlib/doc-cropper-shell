#include "Displayable.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>

#define WIN_SIZE 500

using namespace std;
using namespace cv;

void Displayable::display()
{
    const string &name = this->getDisplayableName();

    namedWindow(name, WINDOW_NORMAL);
    resizeWindow(name, WIN_SIZE, WIN_SIZE);
    imshow(name, this->data);
}

const DisplayData &Displayable::getDisplayableData() const
{
    return this->data;
}
