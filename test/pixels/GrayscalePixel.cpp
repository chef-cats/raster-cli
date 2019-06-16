#include <pixels/GrayscalePixel.hpp>
#include <utils/GrayscalePixel/Constants.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

BOOST_AUTO_TEST_SUITE(GrayscalePixelUnitTests)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_AUTO_TEST_SUITE(BasicTests)

BOOST_DATA_TEST_CASE(CopyConstruction, TEST_DATA, pixel_value)
{
   const GrayscalePixel test_pixel_original(pixel_value);
   const GrayscalePixel test_pixel_copy(test_pixel_original);

   BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyConstruction

BOOST_DATA_TEST_CASE(CopyAssignment, TEST_DATA, pixel_value)
{
   const GrayscalePixel test_pixel_original(pixel_value);
   GrayscalePixel test_pixel_copy(0);
   test_pixel_copy = test_pixel_original;

   BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyAssignment

BOOST_DATA_TEST_CASE(Getter, TEST_DATA, pixel_value)
{
   const GrayscalePixel test_pixel(pixel_value);

   BOOST_CHECK(test_pixel.get_value() == pixel_value);
} // Getter

BOOST_DATA_TEST_CASE(Setter, TEST_DATA, pixel_value)
{
   GrayscalePixel test_pixel(pixel_value);

   BOOST_CHECK(test_pixel.get_value() == pixel_value);

   const unsigned char new_pixel_value = pixel_value + 1;

   test_pixel.set_value(new_pixel_value);

   BOOST_CHECK(test_pixel.get_value() != pixel_value);

} // Setter

BOOST_DATA_TEST_CASE(Equal, TEST_DATA, pixel_value)
{
   const GrayscalePixel lhs(pixel_value);
   const GrayscalePixel rhs(pixel_value);

   BOOST_CHECK(lhs == rhs);
} //Equal

BOOST_DATA_TEST_CASE(NotEqual, TEST_DATA, pixel_value)
{
   const GrayscalePixel lhs(pixel_value);
   const GrayscalePixel rhs(pixel_value + 1);

   BOOST_CHECK(lhs != rhs);
} //Equal

BOOST_AUTO_TEST_SUITE_END(/*BasicTests*/)

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)

BOOST_AUTO_TEST_SUITE_END(/*GrayscalePixelUnitTests*/)