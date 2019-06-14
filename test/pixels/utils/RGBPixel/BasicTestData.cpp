#include "BasicTestData.hpp"

using std::array;
using std::generate;

BasicTestData::BasicTestData(const DataContainer& red_values,
	const DataContainer& green_values, const DataContainer& blue_values) :
	red_values(red_values), green_values(green_values), blue_values(blue_values)
{}
