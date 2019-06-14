#pragma once

#include <array>

struct RGBBasicTestData
{
public:
	RGBBasicTestData();

private:
	static const size_t DATA_SIZE = 10;

	static unsigned char get_random() noexcept;

public:
	std::array<unsigned char, DATA_SIZE> red_values;
	std::array<unsigned char, DATA_SIZE> green_values;
	std::array<unsigned char, DATA_SIZE> blue_values;
};
