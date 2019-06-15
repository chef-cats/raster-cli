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
