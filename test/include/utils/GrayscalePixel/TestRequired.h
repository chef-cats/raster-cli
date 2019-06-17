#pragma once
#include <pixels/GrayscalePixel.hpp>
#include <ostream>

static std::ostream& operator<<(std::ostream& out, const GrayscalePixel& pixel) {
   out << pixel.get_value();
   return out;
}
