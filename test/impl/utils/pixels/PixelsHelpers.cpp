#include <utils/RGBPixel/Helpers.hpp>

#include <pixels/RGBPixel.hpp>
#include <pixels/GrayscalePixel.hpp>

using boost::test_tools::predicate_result;

using std::ostream;

ostream& operator<<(ostream& out, const RGBPixel& rgb_pixel) {
  return out << "(" << static_cast<unsigned int>(rgb_pixel.get_red()) << ", "
             << static_cast<unsigned int>(rgb_pixel.get_green()) << ", "
             << static_cast<unsigned int>(rgb_pixel.get_blue()) << ")";
}

predicate_result compare_pixel_rgb_values(const RGBPixel& pixel, unsigned char red,
                                          unsigned char green, unsigned char blue) {
  predicate_result are_equal = true;
  if (pixel.get_red() != red) {
    are_equal = false;
    are_equal.message() << "\n"
                        << "red = " << static_cast<unsigned int>(pixel.get_red())
                        << ", expected " << static_cast<unsigned int>(red);
  }
  if (pixel.get_green() != green) {
    are_equal = false;
    are_equal.message() << "\n"
                        << "green = " << static_cast<unsigned int>(pixel.get_green())
                        << ", expected " << static_cast<unsigned int>(red);
  }
  if (pixel.get_blue() != blue) {
    are_equal = false;
    are_equal.message() << "\n"
                        << "blue = " << static_cast<unsigned int>(pixel.get_blue())
                        << ", expected " << static_cast<unsigned int>(red);
  }
  return are_equal;
}

std::ostream& operator<<(std::ostream& out, const GrayscalePixel& pixel) {
  out << pixel.get_value();
  return out;
}
