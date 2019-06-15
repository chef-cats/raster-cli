#pragma once

#include <pixels/Pixel.hpp>

#include <string>
#include <vector>

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
	class Metadata;

	virtual ~Image() = default;

	virtual void apply(const ImageOperation& operation) = 0;
	virtual void apply(const ImageOperation& operation, ...) = 0;

	virtual void load() = 0;
	virtual void save() const = 0;

	virtual const std::string& get_file_path() const = 0;
	virtual const std::vector<Pixel>& get_pixels() const = 0;
};