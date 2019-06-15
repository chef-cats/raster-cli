#pragma once

#include "Image.hpp"

class PMBImageMetadata : public Image::Metadata
{
public:
	PMBImageMetadata(const std::string& file_path);
	/// @todo Rethink this
	PMBImageMetadata(const std::string& file_path, std::ifstream& file);

	void load() override;
	void save() const override;

	const std::string& get_path() const override;
	const std::string& get_format() const override;

	size_t get_height() const override;
	size_t get_width() const override;

	unsigned char get_max_value() const override;

private:
	std::string path;
	std::string format;
	
	unsigned int height;
	unsigned int width;

	unsigned int max_value;
};

class PMBImage : public Image
{
public:
	PMBImage(const std::string& file_path);

	void apply(const ImageOperation& operation) override;

	void load() override;
	void save() const override;

	const Metadata& get_metadata() const override;
	const std::vector<std::vector<std::unique_ptr<Pixel>>>& get_pixels() const override;

private:
	PMBImageMetadata metadata;
	std::vector<std::vector<std::unique_ptr<Pixel>>> pixels;
};
