#pragma once

#include <string>

class ImageMetadata
{
public:
	virtual ~ImageMetadata() = default;

	virtual void load() = 0;
	virtual void save() const = 0;

	virtual const std::string& get_path() const = 0;
	virtual const std::string& get_format() const = 0;

	virtual size_t get_height() const = 0;
	virtual size_t get_width() const = 0;

	virtual unsigned char get_max_value() const = 0;
};
