#include <utils/ToMonochrome/Constants.hpp>

const RGBPixel BLACK(0, 0, 0);
const RGBPixel WHITE(255, 255, 255);

const std::array<RGBTestData, 10> TO_MONO_TEST_DATA{{{RGBPixel(0, 0, 0), BLACK},
                                                     {RGBPixel(255, 255, 255), WHITE},
                                                     {RGBPixel(1, 2, 3), BLACK},
                                                     {RGBPixel(125, 125, 125), BLACK},
                                                     {RGBPixel(72, 0, 0), BLACK},
                                                     {RGBPixel(243, 22, 17), BLACK},
                                                     {RGBPixel(11, 222, 175), WHITE},
                                                     {RGBPixel(191, 137, 196), WHITE},
                                                     {RGBPixel(176, 183, 177), WHITE},
                                                     {RGBPixel(161, 204, 237), WHITE}}};