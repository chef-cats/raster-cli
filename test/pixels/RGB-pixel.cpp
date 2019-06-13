#include <pixels/RGB-pixel.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <array>
#include <cstdlib>
#include <ostream>

using std::array;
using std::generate;
using std::ostream;

struct RGBPixelData
{
private:
	static const size_t DATA_SIZE = 10;

	static unsigned char get_random() noexcept
	{
		/*
		 * We use this to 'trim' the random number in the range of
		 * unsigned char. It is static in order not to recompute it every time.
		 */
		static const unsigned short over_uchar_max = UCHAR_MAX + 1;

		/*
		 * We use that unsigned char is bigger than 0,
		 * as is the value returned from rand().
		 */
		return rand() % over_uchar_max;
	}

public:
	RGBPixelData()
	{
		generate(red_values.begin(), red_values.end(), get_random);
		generate(green_values.begin(), green_values.end(), get_random);
		generate(blue_values.begin(), blue_values.end(), get_random);
	}

public:
	array<unsigned char, DATA_SIZE> red_values;
	array<unsigned char, DATA_SIZE> green_values;
	array<unsigned char, DATA_SIZE> blue_values;
};

static const RGBPixelData RGB_PIXEL_TEST_DATA;

bool operator==(const RGBPixel& pixel_a, const RGBPixel& pixel_b) noexcept
{
	return pixel_a.get_red() == pixel_b.get_red() &&
		pixel_a.get_green() == pixel_b.get_green() &&
		pixel_a.get_blue() == pixel_b.get_blue();
}

ostream& operator<<(ostream& out, const RGBPixel& rgb_pixel)
{
	return out << "(" << rgb_pixel.get_red() << ", " << 
		rgb_pixel.get_green() << ", " << 
		rgb_pixel.get_blue() << ")";
}

BOOST_AUTO_TEST_SUITE(RGBPixelUnitTests)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_DATA_TEST_CASE(Construcion, RGB_PIXEL_TEST_DATA.red_values ^
                                  RGB_PIXEL_TEST_DATA.green_values ^
                                  RGB_PIXEL_TEST_DATA.blue_values,
                                  red, green, blue)
{
	const RGBPixel test_pixel(red, green, blue);

	BOOST_CHECK_EQUAL(test_pixel.get_red(), red);
	BOOST_CHECK_EQUAL(test_pixel.get_green(), green);
	BOOST_CHECK_EQUAL(test_pixel.get_blue(), blue);
} // Construction

BOOST_DATA_TEST_CASE(CopyConstrucion,
	RGB_PIXEL_TEST_DATA.red_values^
	RGB_PIXEL_TEST_DATA.green_values^
	RGB_PIXEL_TEST_DATA.blue_values,
	red, green, blue)
{
	const RGBPixel test_pixel_original(red, green, blue);
	const RGBPixel test_pixel_copy(test_pixel_original);

	BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyConstrucion

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)

BOOST_AUTO_TEST_SUITE_END(/*RGBPixelUnitTests*/)
