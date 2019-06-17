#include <operations/ToMonochrome.hpp>
#include <pixels/RGBPixel.hpp>

#include <cmath>

static const RGBPixel BLACK(0, 0, 0);
static const RGBPixel WHITE(255, 255, 255);

static double calc_proximity_heuristic(const RGBPixel& pixel_a, const RGBPixel& pixel_b) {
  return sqrt(pow(pixel_a.get_red() - pixel_b.get_red(), 2)
              + pow(pixel_a.get_green() - pixel_b.get_green(), 2)
              + pow(pixel_a.get_blue() - pixel_b.get_blue(), 2));
}

void ToMonochrome::apply_to(RGBPixel& pixel) const {
  const double heuristic_to_black = calc_proximity_heuristic(pixel, BLACK);
  const double heuristic_to_white = calc_proximity_heuristic(pixel, WHITE);

  pixel = heuristic_to_black < heuristic_to_white ? BLACK : WHITE;
}