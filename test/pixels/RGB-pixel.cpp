#include <pixels/RGB-pixel.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <array>
#include <cstdlib>

using std::array;
using std::generate;

struct RGBPixelData
{
private:
	static const size_t DATA_SIZE = 10;

	static unsigned char get_random()
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
		generate(r_vals.begin(), r_vals.end(), get_random);
		generate(g_vals.begin(), g_vals.end(), get_random);
		generate(b_vals.begin(), b_vals.end(), get_random);
	}

public:
	array<unsigned char, DATA_SIZE> r_vals;
	array<unsigned char, DATA_SIZE> g_vals;
	array<unsigned char, DATA_SIZE> b_vals;
};

static const RGBPixelData RGB_PIXEL_TEST_DATA;

BOOST_AUTO_TEST_SUITE(RGBPixelUnitTests)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_DATA_TEST_CASE(Construcion, RGB_PIXEL_TEST_DATA.r_vals ^
                                  RGB_PIXEL_TEST_DATA.g_vals ^
                                  RGB_PIXEL_TEST_DATA.b_vals,
                                  r, g, b)
{
	const RGBPixel test_pixel(r, g, b);

	BOOST_CHECK_EQUAL(test_pixel.get_red(), r);
	BOOST_CHECK_EQUAL(test_pixel.get_green(), g);
	BOOST_CHECK_EQUAL(test_pixel.get_blue(), b);
} // Construction

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)

BOOST_AUTO_TEST_SUITE_END(/*RGBPixelUnitTests*/)
