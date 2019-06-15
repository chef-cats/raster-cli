#pragma once

#include "Pixel.hpp"
#include <operations/Operation.hpp>

/**
 * Class describing a Grayscale pixel.
 *
 * This class is inheritor of the Pixel and represent pixels
 * which have a range [0, 255].
 */

class GrayscalePixel : public Pixel
{
public:
   GrayscalePixel() = delete;
   virtual ~GrayscalePixel() = default;
   GrayscalePixel(const GrayscalePixel&) = default;
   GrayscalePixel(GrayscalePixel&&) = default;
   GrayscalePixel& operator=(const GrayscalePixel&) = default;
   GrayscalePixel& operator=(GrayscalePixel&&) = default;

public:
   explicit GrayscalePixel(unsigned char value) noexcept;

public:
   void apply(const Operation& operation) override;

public:
   unsigned char get_value() const noexcept;
   void set_value(unsigned char new_value) noexcept;

private:
   unsigned char _value;
};
