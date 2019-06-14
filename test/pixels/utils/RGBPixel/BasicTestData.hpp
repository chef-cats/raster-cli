#pragma once

#include <array>

struct BasicTestData
{
private:
	static const size_t DATA_SIZE = 10;

public:
	using DataContainer = std::array<unsigned char, DATA_SIZE>;

	BasicTestData(const DataContainer& red_values, 
		const DataContainer& green_values, const DataContainer& blue_values);

public:
	DataContainer red_values;
	DataContainer green_values;
	DataContainer blue_values;
};
