#pragma once

#include <pixels/Pixel.hpp>

#include <string>
#include <memory>
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

	virtual void load() = 0;
	virtual void save() const = 0;

	virtual const Metadata& get_metadata() const = 0;
	virtual const std::vector<std::vector<std::unique_ptr<Pixel>>>& get_pixels() const = 0;
};

class Image::Metadata
{
public:
	virtual ~Metadata() = default;

	virtual void load() = 0;
	virtual void save() const = 0;

	virtual const std::string& get_path() const = 0;
	virtual const std::string& get_format() const = 0;

	virtual size_t get_height() const = 0;
	virtual size_t get_width() const = 0;

	virtual unsigned char get_max_value() const = 0;
};