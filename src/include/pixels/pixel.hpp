#pragma once

class Operation;

class Pixel
{
public:
	virtual ~Pixel() = default;

	virtual void apply(const Operation& operation) = 0;
};
