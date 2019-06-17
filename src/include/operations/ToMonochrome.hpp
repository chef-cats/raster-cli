#pragma once

#include "Operation.hpp"

class ToMonochrome : public Operation {
public:
  void apply_to(RGBPixel& pixel) const override;
  void apply_to(GrayscalePixel& pixel) const override { /*   TODO    */ }
};