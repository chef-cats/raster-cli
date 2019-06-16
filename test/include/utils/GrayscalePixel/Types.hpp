#pragma once

#include <array>

namespace types {
   template<size_t size>
   using CharContainer = std::array<unsigned char, size>;
};
