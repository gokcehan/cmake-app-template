#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

#include "hello.h"

BOOST_AUTO_TEST_CASE(Hello)
{
    BOOST_CHECK_MESSAGE(hello("world") == 0, "greeting failed");
}
