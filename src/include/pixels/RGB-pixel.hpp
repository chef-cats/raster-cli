#pragma once

#include "pixel.hpp"

class RGBPixel : public Pixel
{
public:
	explicit RGBPixel(unsigned char r, unsigned char g, unsigned char b) noexcept;

public:
	void apply(const Operation& operation) override;

public:
	unsigned char get_red() const noexcept;
	void set_red(unsigned char) noexcept;

	unsigned char get_green() const noexcept;
	void set_green(unsigned char) noexcept;

	unsigned char get_blue() const noexcept;
	void set_blue(unsigned char) noexcept;

private:
	unsigned char _red;
	unsigned char _green;
	unsigned char _blue;
};
