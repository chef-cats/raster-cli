#pragma once

class PMBImage;

class ImageOperation
{
public:
	virtual ~ImageOperation() = default;

	virtual void apply_to(PMBImage& image) const = 0;
};