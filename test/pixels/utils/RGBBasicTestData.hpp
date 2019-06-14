#pragma once

#include <array>

using std::array;
using std::generate;

struct RGBBasicTestData
{
public:
	RGBBasicTestData();

private:
	static const size_t DATA_SIZE = 10;

	static unsigned char get_random() noexcept;

public:
	array<unsigned char, DATA_SIZE> red_values;
	array<unsigned char, DATA_SIZE> green_values;
	array<unsigned char, DATA_SIZE> blue_values;
};
