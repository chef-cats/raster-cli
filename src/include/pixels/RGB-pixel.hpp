#pragma once

#include "pixel.hpp"

class RGBPixel : public Pixel
{
public:
	RGBPixel() = delete;
	~RGBPixel() = default;
	RGBPixel(const RGBPixel&) = default;
	RGBPixel(RGBPixel&&) = default;
	RGBPixel& operator=(const RGBPixel&) = default;
	RGBPixel& operator=(RGBPixel&&) = default;

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
