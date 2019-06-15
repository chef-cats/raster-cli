#include <images/PMBImage.hpp>
#include <pixels/RGBPixel.hpp>

#include <cstring>
#include <fstream>

using std::ifstream;
using std::strcmp;

PMBImageMetadata::PMBImageMetadata(const std::string& file_path) :
	path(file_path)
{
	load();
}

void PMBImageMetadata::load()
{
	ifstream in(path);

	std::string file_format;
	in >> file_format;

	unsigned int file_width;
	in >> file_width;

	unsigned int file_height;
	in >> file_height;

	unsigned char file_max_value;
	if (file_format == "P3" || file_format == "P6" || file_format == "P2" || file_format == "P5") {
		in >> file_max_value;
	}

	format = file_format;
	height = file_height;
	width = file_width;
	max_value = file_max_value;
}

void PMBImageMetadata::save() const {

}

const std::string& PMBImageMetadata::get_path() const
{
	return path;
}

const std::string& PMBImageMetadata::get_format() const
{
	return format;
}

size_t PMBImageMetadata::get_height() const
{
	return height;
}

size_t PMBImageMetadata::get_width() const
{
	return width;
}

unsigned char PMBImageMetadata::get_max_value() const
{
	return max_value;
}

PMBImage::PMBImage(const std::string& file_path) :
	metadata(file_path)
{
	load();
}

void PMBImage::apply(const ImageOperation& operation)
{
	operation.apply_to(*this);
}

void PMBImage::load()
{
	std::vector<std::vector<std::unique_ptr<Pixel>>> file_pixels(metadata.get_height());
	for (auto& pixel_row : file_pixels) {
		pixel_row.resize(metadata.get_width());

		if (metadata.get_format() == "P3") {
			unsigned char red;
			unsigned char green;
			unsigned char blue;

			for (auto& pixel : pixel_row) {
				in >> red;
				in >> green;
				in >> blue;

				if (red <= metadata.get_max_value() && green <= metadata.get_max_value() && blue <= metadata.get_max_value()) {
					pixel = std::make_unique<RGBPixel>(red, green, blue);
				}
			}
		}
	}
}

void PMBImage::save() const
{

}

const Image::Metadata& PMBImage::get_metadata() const
{
	return metadata;
}

const std::vector<std::vector<std::unique_ptr<Pixel>>>& PMBImage::get_pixels() const
{
	return pixels;
}