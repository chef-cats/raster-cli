#pragma once

class Filter;

class Pixel
{
public:
	virtual ~Pixel() = default;

	virtual void apply(const Filter& filter) = 0;
};