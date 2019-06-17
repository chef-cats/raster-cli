#pragma once
#include <pixels/MonochromePixel.hpp>
#include <utils/MonochromePixel/Constants.hpp>
#include <utils/MonochromePixel/TestRequired.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

BOOST_AUTO_TEST_SUITE(MonochromePixelUnitTests)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_AUTO_TEST_SUITE(BasicTests)

BOOST_DATA_TEST_CASE(Construction, CORRECT_TEST_DATA, value)
{
   const MonochromePixel test_pixel(value);

   BOOST_CHECK(test_pixel.get_value() == value);
} // Construction

BOOST_DATA_TEST_CASE(CopyConstruction, CORRECT_TEST_DATA, value)
{
   const MonochromePixel test_pixel_original(value);
   const MonochromePixel test_pixel_copy(test_pixel_original);

   BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyConstruction

BOOST_DATA_TEST_CASE(CopyAssignment, CORRECT_TEST_DATA, value)
{
   const MonochromePixel test_pixel_original(value);
   MonochromePixel test_pixel_copy(0);
   test_pixel_copy = test_pixel_original;

   BOOST_CHECK_EQUAL(test_pixel_original, test_pixel_copy);
} // CopyAssignment

BOOST_DATA_TEST_CASE(Getters, CORRECT_TEST_DATA, value)
{
   const MonochromePixel test_pixel(value);

   BOOST_CHECK(test_pixel.get_value() == value);
} // Getter

BOOST_DATA_TEST_CASE(Setters, CORRECT_TEST_DATA, value)
{
   MonochromePixel test_pixel(value);

   BOOST_CHECK(test_pixel.get_value() == value);

   const unsigned char new_value = value + 1;

   test_pixel.set_value(new_value);

   BOOST_CHECK(test_pixel.get_value() == value);

} // Setter

BOOST_AUTO_TEST_SUITE_END(/*BasicTests*/)

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)


BOOST_AUTO_TEST_SUITE(NegativeUnitTests)

BOOST_AUTO_TEST_SUITE(BasicTests)

BOOST_DATA_TEST_CASE(Construction, INCORRECT_TEST_DATA, value)
{
   BOOST_CHECK_EXCEPTION(MonochromePixel(value), std::exception, true);
} // Construction

BOOST_DATA_TEST_CASE(Setters, CORRECT_TEST_DATA^ INCORRECT_TEST_DATA, 
                    correct_value, incorrect_value)
{
   MonochromePixel test_pixel(correct_value);

   BOOST_CHECK(test_pixel.get_value() == correct_value);

   test_pixel.set_value(incorrect_value);

   BOOST_CHECK(test_pixel.set_value(incorrect_value), 
               std::exception, 
               test_pixel.get_value() == correct_value);
} // Setter

BOOST_AUTO_TEST_SUITE_END(/*BasicTests*/)

BOOST_AUTO_TEST_SUITE_END(/*NegativeUnitTests*/)


BOOST_AUTO_TEST_SUITE_END(/*MonochromePixelUnitTests*/)