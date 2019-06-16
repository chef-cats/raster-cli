#include <pixels/GrayscalePixel.hpp>
#include <exception>

/**
 * Constructs an grayscale pixel
 */
GrayscalePixel::GrayscalePixel(unsigned char value) noexcept : _value(value)
{}

/**
 * Apply a transformation into the pixel.
 *
 * The transformation must be a inheritor of the Operation class
 * @see Operation
 *
 * @param[in] operation - the desired transformation that has to be applied.
 */
void GrayscalePixel::apply(const Operation& operation)
{
   operation.apply_to(*this);
}

unsigned char GrayscalePixel::get_value() const noexcept
{
   return _value;
}

void GrayscalePixel::set_value(unsigned char new_value) noexcept
{
   _value = new_value;
}

bool operator==(const GrayscalePixel& lhs, const GrayscalePixel& rhs)
{
   return lhs.get_value() == rhs.get_value();
}

bool operator!=(const GrayscalePixel& lhs, const GrayscalePixel& rhs)
{
   return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& out, const GrayscalePixel& pixel)
{
   out << static_cast<int>(pixel.get_value());
   return out;
}

std::istream& operator>>(std::istream& in, GrayscalePixel& pixel)
{
   unsigned int value = 0;
   in >> value;
   if (value > 255) {
      throw std::exception("Try to read Grayscale pixel value which is not"
         "valid!");
   }
   char new_value = static_cast<char>(value);
   pixel.set_value(new_value);
   return in;
}
