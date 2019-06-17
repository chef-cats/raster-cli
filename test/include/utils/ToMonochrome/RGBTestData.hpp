#pragma once

#include <pixels/RGBPixel.hpp>

struct RGBTestData {
  RGBTestData(const RGBPixel& input_pixel, const RGBPixel& expected_pixel)
      : input_pixel(input_pixel), expected_pixel(expected_pixel) {}

  RGBPixel input_pixel;
  RGBPixel expected_pixel;
};