#include <pixels/RGBPixel.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <array>
#include <cstdlib>
#include <ostream>

using boost::test_tools::predicate_result;

using std::array;
using std::generate;
using std::ostream;

struct RGBPixelData
{
public:
	RGBPixelData()
	{
		generate(red_values.begin(), red_values.end(), get_random);
		generate(green_values.begin(), green_values.end(), get_random);
		generate(blue_values.begin(), blue_values.end(), get_random);
	}

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
	array<unsigned char, DATA_SIZE> red_values;
	array<unsigned char, DATA_SIZE> green_values;
	array<unsigned char, DATA_SIZE> blue_values;
};

static const RGBPixelData RGB_PIXEL_TEST_DATA;

static bool operator==(const RGBPixel& pixel_a, const RGBPixel& pixel_b) noexcept
{
	return pixel_a.get_red() == pixel_b.get_red() &&
		pixel_a.get_green() == pixel_b.get_green() &&
		pixel_a.get_blue() == pixel_b.get_blue();
}

static ostream& operator<<(ostream& out, const RGBPixel& rgb_pixel)
{
	return out << "(" << static_cast<unsigned int>(rgb_pixel.get_red()) << ", " <<
		static_cast<unsigned int>(rgb_pixel.get_green()) << ", " <<
		static_cast<unsigned int>(rgb_pixel.get_blue()) << ")";
}

static predicate_result compare_pixel_rgb_values(const RGBPixel& pixel,
	unsigned char red, unsigned char green, unsigned char blue)
{
	predicate_result are_equal = true;
	if (pixel.get_red() != red) {
		are_equal = false;
		are_equal.message() << "\n" <<
			"red = " << static_cast<unsigned int>(pixel.get_red()) <<
			", expected " << static_cast<unsigned int>(red);
	}
	if (pixel.get_green() != green) {
		are_equal = false;
		are_equal.message() << "\n" <<
			"green = " << static_cast<unsigned int>(pixel.get_green()) <<
			", expected " << static_cast<unsigned int>(red);
	}
	if (pixel.get_blue() != blue) {
		are_equal = false;
		are_equal.message() << "\n" <<
			"blue = " << static_cast<unsigned int>(pixel.get_blue()) <<
			", expected " << static_cast<unsigned int>(red);
	}
	return are_equal;
}

BOOST_AUTO_TEST_SUITE(RGBPixelUnitTests)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_DATA_TEST_CASE(Construcion, RGB_PIXEL_TEST_DATA.red_values ^
                                  RGB_PIXEL_TEST_DATA.green_values ^
                                  RGB_PIXEL_TEST_DATA.blue_values,
                                  red, green, blue)
{
	const RGBPixel test_pixel(red, green, blue);

	BOOST_CHECK(compare_pixel_rgb_values(test_pixel, red, green, blue));
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

BOOST_DATA_TEST_CASE(CopyAssignment,
	RGB_PIXEL_TEST_DATA.red_values^
	RGB_PIXEL_TEST_DATA.green_values^
	RGB_PIXEL_TEST_DATA.blue_values,
	red, green, blue)
{
	const RGBPixel test_pixel_original(red, green, blue);
	RGBPixel test_pixel_copy(0, 0, 0);
	test_pixel_copy = test_pixel_original;

	BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyAssignment

BOOST_DATA_TEST_CASE(Setters,
	RGB_PIXEL_TEST_DATA.red_values^
	RGB_PIXEL_TEST_DATA.green_values^
	RGB_PIXEL_TEST_DATA.blue_values,
	red, green, blue)
{
	RGBPixel test_pixel(red, green, blue);

	BOOST_CHECK(compare_pixel_rgb_values(test_pixel, red, green, blue));

	const unsigned char new_red = red + 1;
	const unsigned char new_green = green + 1;
	const unsigned char new_blue = blue + 1;

	test_pixel.set_red(new_red);
	test_pixel.set_green(new_green);
	test_pixel.set_blue(new_blue);

	BOOST_CHECK(compare_pixel_rgb_values(test_pixel, new_red, new_green, new_blue));

} // Setters

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)

BOOST_AUTO_TEST_SUITE_END(/*RGBPixelUnitTests*/)
