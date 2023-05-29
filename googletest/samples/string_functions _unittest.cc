#include <string.h>

#include "string_functions.h"
#include "gtest/gtest.h"

namespace {

// Tests the upper case function
TEST(OurStringFunctions, ToUpperCase) {
    EXPECT_TRUE("CIAO" == ToUpperCase("cIaO"));
    EXPECT_TRUE("CIAO" == ToUpperCase("ciao"));
    EXPECT_TRUE("CIAO" == ToUpperCase("CIAO"));
    EXPECT_TRUE("CIAO0!" == ToUpperCase("Ciao0!"));
}

}
