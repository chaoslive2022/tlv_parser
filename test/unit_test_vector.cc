#include <gtest/gtest.h>

// Demonstrate some basic assertions
TEST(tlv_parser_create, BasicAssertions)
{
    // Expect two strings not to be equal
    EXPECT_STRNE("hello", "world");
}

TEST(tlv_parser_first, BasicAssertions)
{
    // Expect equality
    EXPECT_EQ(7 * 6, 42);
}
