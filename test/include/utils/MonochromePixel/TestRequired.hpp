#pragma once
#include <pixels/MonochromePixel.hpp>
#include <iostream>

static std::ostream& operator<<(std::ostream& out, const MonochromePixel& pixel) {
   out << pixel.get_value();
   return out;
}