#include <pixels/RGB-pixel.hpp>
#include <pixels/operations/operation.hpp>

RGBPixel::RGBPixel(unsigned char r, unsigned char g, unsigned char b) :
	_r(r), _g(g), _b(b)
{}

void RGBPixel::apply(const Operation& operation)
{
	operation.apply_to(*this);
}

unsigned char RGBPixel::r() const
{
	return _r;
}

void RGBPixel::r(unsigned char r)
{
	_r = r;
}

unsigned char RGBPixel::g() const
{
	return _g;
}

void RGBPixel::g(unsigned char g)
{
	_g = g;
}

unsigned char RGBPixel::b() const
{
	return _b;
}

void RGBPixel::b(unsigned char b)
{
	_b = b;
}
