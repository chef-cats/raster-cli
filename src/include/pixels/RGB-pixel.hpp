#pragma once

#include "pixel.hpp"

class RGBPixel : public Pixel
{
public:
	explicit RGBPixel(unsigned char r, unsigned char g, unsigned char b);

public:
	void apply(const Operation& operation) override;

public:
	unsigned char get_red() const;
	void set_red(unsigned char);

	unsigned char get_green() const;
	void set_green(unsigned char);

	unsigned char get_blue() const;
	void set_blue(unsigned char);

private:
	unsigned char _red;
	unsigned char _green;
	unsigned char _blue;
};
