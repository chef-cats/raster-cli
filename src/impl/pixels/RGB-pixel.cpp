#include <pixels/RGB-pixel.hpp>
#include <pixels/operations/operation.hpp>

RGBPixel::RGBPixel(unsigned char r, unsigned char g, unsigned char b) noexcept :
	_red(r), _green(g), _blue(b)
{}

void RGBPixel::apply(const Operation& operation)
{
	operation.apply_to(*this);
}

unsigned char RGBPixel::get_red() const noexcept
{
	return _red;
}

void RGBPixel::set_red(unsigned char r) noexcept
{
	_red = r;
}

unsigned char RGBPixel::get_green() const noexcept
{
	return _green;
}

void RGBPixel::set_green(unsigned char g) noexcept
{
	_green = g;
}

unsigned char RGBPixel::get_blue() const noexcept
{
	return _blue;
}

void RGBPixel::set_blue(unsigned char b) noexcept
{
	_blue = b;
}
