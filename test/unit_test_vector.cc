#include <gtest/gtest.h>

// Demonstrate some basic assertions
TEST(unit_test_vector, BasicAssertions)
{
    // Expect two strings not to be equal
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}
