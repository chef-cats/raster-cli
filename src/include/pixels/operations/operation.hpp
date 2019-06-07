#pragma once

class RGBPixel;

class Operation
{
public:
	virtual ~Operation() = default;

public:
	virtual void apply_to(RGBPixel&) const = 0;
};
