
#pragma once
#include <vector>
using namespace std;


struct Pixel {
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    bool operator==(const Pixel& rhs) const;
};

///

bool Pixel::operator==(const Pixel& rhs) const {

    unsigned char b = this->blue;
    unsigned char g = this->green;
    unsigned char r = this->red;

    if (b != rhs.blue || g != rhs.green || r != rhs.red) {

        return false;
    }

    return true;
}
