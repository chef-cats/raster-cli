#pragma once

#include "ImageMetadata.hpp"

class Pixel;

/**
 * Forward declaration of ImageOperation.
 *
 * @see ImageOperation
 */

class ImageOperation;

/**
 * Base class of the image hierarchy.
 *
 * This and ImageOperation are implemented using the
 * <a href="https://sourcemaking.com/design_patterns/visitor">visitor design pattern</a>.
 * ImageOperation is the visitor class.
 */

class Image
{
public:
	virtual ~Image() = default;

	virtual void apply(const ImageOperation& operation) = 0;

	virtual const ImageMetadata& get_metadata() const = 0;

	virtual Pixel& get_pixel(size_t width, size_t height) = 0;
	virtual const Pixel& get_pixel(size_t width, size_t height) const = 0;
};
