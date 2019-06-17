#pragma once

#include <boost/test/unit_test.hpp>

class RGBPixel;
struct RGBTestData;

std::ostream& operator<<(std::ostream& out, const RGBPixel& rgb_pixel);

boost::test_tools::predicate_result compare_pixel_rgb_values(const RGBPixel& pixel,
                                                             unsigned char red,
                                                             unsigned char green,
                                                             unsigned char blue);
