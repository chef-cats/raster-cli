#include <pixels/RGB-pixel.hpp>
#include <pixels/operations/operation.hpp>

RGBPixel::RGBPixel(unsigned char r, unsigned char g, unsigned char b) :
	_red(r), _green(g), _blue(b)
{}

void RGBPixel::apply(const Operation& operation)
{
	operation.apply_to(*this);
}

unsigned char RGBPixel::get_red() const
{
	return _red;
}

void RGBPixel::set_red(unsigned char r)
{
	_red = r;
}

unsigned char RGBPixel::get_green() const
{
	return _green;
}

void RGBPixel::set_green(unsigned char g)
{
	_green = g;
}

unsigned char RGBPixel::get_blue() const
{
	return _blue;
}

void RGBPixel::set_blue(unsigned char b)
{
	_blue = b;
}
