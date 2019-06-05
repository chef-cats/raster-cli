#pragma once

class Filter;

class Pixel
{
public:
	virtual ~Pixel() = default;

	void apply(const Filter& filter);
};