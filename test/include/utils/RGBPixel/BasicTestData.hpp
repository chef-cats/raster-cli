#pragma once

#include <array>

template <std::size_t DATA_SIZE>
struct BasicTestData {
public:
  using DataContainer = std::array<unsigned char, DATA_SIZE>;

  BasicTestData(const DataContainer &red_values, const DataContainer &green_values,
                const DataContainer &blue_values)
      : red_values(red_values), green_values(green_values), blue_values(blue_values){};

public:
  DataContainer red_values;
  DataContainer green_values;
  DataContainer blue_values;
};
