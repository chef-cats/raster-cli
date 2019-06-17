#include <utils/RGBPixel/Helpers.hpp>
#include <utils/ToMonochrome/Helpers.hpp>
#include <utils/ToMonochrome/RGBTestData.hpp>

using std::ostream;

ostream& operator<<(ostream& out, const RGBTestData& data) {
  return out << "Input pixel: " << data.input_pixel
             << "; Expected pixel: " << data.expected_pixel;
}
