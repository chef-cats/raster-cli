#pragma once
#include <pixels/Pixel.hpp>

/**
 * Class describing a Monochrome pixel.
 *
 * This class is inheritor of the Pixel and represent pixels
 * which have 2 possible values - 0(white) and 1(black).
 */

class MonochromePixel {
   enum class MonochromeValue : unsigned char {
      White = 0,
      Black = 1,
      Invalid = 2,
   };

public:
   MonochromePixel(unsigned char value);
   MonochromePixel(const MonochromePixel& other) = default;
   MonochromePixel(MonochromePixel&& other) = default;
   MonochromePixel& operator=(const MonochromePixel& rhs) = default;
   MonochromePixel& operator=(MonochromePixel&& rhs) = default;
   virtual ~MonochromePixel() = default;

public:
   unsigned char get_value() const noexcept;
   void set_value(unsigned char value);

private:
   MonochromeValue _value;
};

bool operator==(const MonochromePixel& lhs, const MonochromePixel& rhs);
bool operator!=(const MonochromePixel& lhs, const MonochromePixel& rhs);