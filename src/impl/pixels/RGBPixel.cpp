#include <pixels/RGBPixel.hpp>
#include <operations/Operation.hpp>

RGBPixel::RGBPixel(unsigned char red, unsigned char green, unsigned char blue) noexcept :
	_red(red), _green(green), _blue(blue)
{}

void RGBPixel::apply(const Operation& operation)
{
	operation.apply_to(*this);
}

unsigned char RGBPixel::get_red() const noexcept
{
	return _red;
}

void RGBPixel::set_red(unsigned char red) noexcept
{
	_red = red;
}

unsigned char RGBPixel::get_green() const noexcept
{
	return _green;
}

void RGBPixel::set_green(unsigned char green) noexcept
{
	_green = green;
}

unsigned char RGBPixel::get_blue() const noexcept
{
	return _blue;
}

void RGBPixel::set_blue(unsigned char blue) noexcept
{
	_blue = blue;
}
