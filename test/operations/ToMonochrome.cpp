#include <operations/ToMonochrome.hpp>
#include <pixels/RGBPixel.hpp>

#include <utils/RGBPixel/Helpers.hpp>
#include <utils/ToMonochrome/BasicFixture.hpp>
#include <utils/ToMonochrome/Constants.hpp>
#include <utils/ToMonochrome/Helpers.hpp>

#include <boost/test/data/test_case.hpp>
#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(ToMonochromeUnitTests, BasicFixture)

BOOST_AUTO_TEST_SUITE(PositiveUnitTests)

BOOST_DATA_TEST_CASE(ApplyToRGBPixel, TO_MONO_TEST_DATA, test_data_sample) {
  RGBTestData test_data(test_data_sample);

  test_data.input_pixel.apply(to_monochrome);
  BOOST_CHECK_EQUAL(test_data.input_pixel, test_data.expected_pixel);
}

BOOST_AUTO_TEST_SUITE_END(/*PositiveUnitTests*/)

BOOST_AUTO_TEST_SUITE_END(/*ToMonochromeUnitTests*/)