#pragma once

/**
 * Forward declaration of RGBPixel.
 *
 * @see RGBPixel
 */

class RGBPixel;

/**
 * Base class of the pixel operation hierarchy.
 *
 * This and Pixel are implemented using the
 * <a href="https://sourcemaking.com/design_patterns/visitor">visitor design pattern</a>.
 * Operation is the visitor class.
 */

class Operation
{
public:
	virtual ~Operation() = default;

public:
	virtual void apply_to(RGBPixel& pixel) const = 0;
};
