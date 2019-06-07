#pragma once

#include "pixel.hpp"

class RGBPixel : public Pixel
{
public:
	RGBPixel(unsigned char r, unsigned char g, unsigned char b);

public:
	void apply(const Operation& operation) override;

public:
	unsigned char r() const;
	void r(unsigned char);

	unsigned char g() const;
	void g(unsigned char);

	unsigned char b() const;
	void b(unsigned char);

private:
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;
};
