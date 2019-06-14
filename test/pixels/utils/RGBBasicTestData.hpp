#pragma once

#include <array>

using std::array;
using std::generate;

struct RGBPixelData
{
public:
	RGBPixelData()
	{
		generate(red_values.begin(), red_values.end(), get_random);
		generate(green_values.begin(), green_values.end(), get_random);
		generate(blue_values.begin(), blue_values.end(), get_random);
	}

private:
	static const size_t DATA_SIZE = 10;

	static unsigned char get_random() noexcept
	{
		/*
			* We use this to 'trim' the random number in the range of
			* unsigned char. It is static in order not to recompute it every time.
			*/
		static const unsigned short over_uchar_max = UCHAR_MAX + 1;

		/*
			* We use that unsigned char is bigger than 0,
			* as is the value returned from rand().
			*/
		return rand() % over_uchar_max;
	}

public:
	array<unsigned char, DATA_SIZE> red_values;
	array<unsigned char, DATA_SIZE> green_values;
	array<unsigned char, DATA_SIZE> blue_values;
};
