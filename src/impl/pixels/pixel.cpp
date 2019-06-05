#include <pixels/pixel.hpp>

void Pixel::apply(const Filter& filter)
{
	filter.apply_to(*this);
}