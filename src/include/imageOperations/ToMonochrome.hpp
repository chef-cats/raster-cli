#pragma once

#include "ImageOperation.hpp"

#include <operations/ToMonochrome.hpp>
#include <images/PMBImage.hpp>

class ToMonochrome : public ImageOperation
{
public:
	void apply_to(PMBImage& image) const override {
		const size_t image_width = image.get_metadata().get_width();
		const size_t image_height = image.get_metadata().get_height();

		for (size_t y = 0; y < image_height; ++y) {
			for (size_t x = 0; x < image_width; ++x) {
				image.get_pixel(y, x).apply(to_monochrome);
			}
		}
	}

private:
	ToMonochrome to_monochrome;
};