#include "sample1.h"
#include "sample2.h"
#include "sample3-inl.h"
#include "sample4.h"

#include <limits.h>

#include "gtest/gtest.h"


// From sample1: 
TEST(FactorialTest, Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(1, Factorial(6)); // dovrebbe dare errore
  EXPECT_EQ(2, Factorial(2));
  EXPECT_GT(Factorial(-10), 0);

  // <TechnicalDetails>
  //
  // EXPECT_EQ(expected, actual) is the same as
  //
  //   EXPECT_TRUE((expected) == (actual))
  //
  // except that it will print both the expected value and the actual
  // value when the assertion fails.  This is very helpful for
  // debugging.  Therefore in this case EXPECT_EQ is preferred.
  //
  // On the other hand, EXPECT_TRUE accepts any Boolean expression,
  // and is thus more general.
  //
  // </TechnicalDetails>
}
// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));
  EXPECT_TRUE(IsPrime(3));
}

// Returns 12 always (with every input double type) 
TEST (isAndreaTest, TrivialCase) {
    EXPECT_EQ(12, Andrea(3.2));
}
// FUDE return the triple of the input 
TEST (isFudeTest, Normal) {
    EXPECT_EQ(12, FUDE(3));
    EXPECT_EQ(4, FUDE(2));
}

// From sample3:
TEST(Counter, Increment) {
  Counter c;

  // Test that counter 0 returns 0
  EXPECT_EQ(0, c.Decrement());

  // EXPECT_EQ() evaluates its arguments exactly once, so they
  // can have side effects.

  EXPECT_EQ(0, c.Increment());
  EXPECT_EQ(1, c.Increment());
  EXPECT_EQ(2, c.Increment());

  EXPECT_EQ(3, c.Decrement());
}


// Main with RUN_ALL_TESTS()
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
