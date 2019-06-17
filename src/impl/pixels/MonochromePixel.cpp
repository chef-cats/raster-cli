#include <pixels/MonochromePixel.hpp>
#include <exception>

MonochromePixel::MonochromePixel(unsigned char value) {
   set_value(value);
}

unsigned char MonochromePixel::get_value() const noexcept { 
   return static_cast<unsigned char>(_value); 
}

void MonochromePixel::set_value(unsigned char value) {
   unsigned char invalid = static_cast<unsigned char>(MonochromeValue::Invalid);
   if (value >= invalid) {
      throw std::exception("Try to set invalid value");
   }
   _value = static_cast<MonochromeValue>(value);
}

bool operator==(const MonochromePixel& lhs, const MonochromePixel& rhs) {
   return lhs.get_value() == rhs.get_value();
}

bool operator!=(const MonochromePixel& lhs, const MonochromePixel& rhs)
{
   return !(lhs == rhs);
}
