//---

#include "string_utils.h"
#include <cstring>

#include <gtest/gtest.h>

//---

TEST(Test_string_utils, GIVEN_buffer_size_0_and_value_size_0_WHEN_strlcpy_THEN_copies_all_bytes)
{
    // GIVEN
    char array_sized[] = "";
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "");

    // THEN
    ASSERT_STREQ(result,      "");
    ASSERT_STREQ(array_sized, "");
}

TEST(Test_string_utils, GIVEN_buffer_size_5_and_value_size_0_WHEN_strlcpy_THEN_copies_all_bytes)
{
    // GIVEN
    char array_sized[5];
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "");

    // THEN
    ASSERT_STREQ(result,      "");
    ASSERT_STREQ(array_sized, "");
}

TEST(Test_string_utils, GIVEN_buffer_size_0_and_value_size_5_WHEN_strlcpy_THEN_copies_all_bytes)
{
    // GIVEN
    char array_sized[] = "";
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "12345");

    // THEN
    ASSERT_STREQ(result,      "");
    ASSERT_STREQ(array_sized, "");
}

TEST(Test_string_utils, GIVEN_buffer_size_6_and_value_size_5_WHEN_strlcpy_THEN_copies_all_bytes)
{
    // GIVEN
    char array_sized[6];
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "12345");

    // THEN
    ASSERT_STREQ(result,      "12345");
    ASSERT_STREQ(array_sized, "12345");
}

TEST(Test_string_utils, GIVEN_buffer_size_5_and_value_size_5_WHEN_strlcpy_THEN_copies_all_bytes_except_last)
{
    // GIVEN
    char array_sized[5];
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "12345");

    // THEN
    ASSERT_STREQ(result,      "1234");
    ASSERT_STREQ(array_sized, "1234");
}

TEST(Test_string_utils, GIVEN_buffer_size_7_and_value_size_5_WHEN_strlcpy_THEN_copies_all_bytes)
{
    // GIVEN
    char array_sized[7];
    memset(array_sized, 0xAA, sizeof(array_sized));

    // WHEN
    char* result = strlcpy_P(array_sized, "12345");

    // WHEN THEN
    ASSERT_STREQ(result,      "12345");
    ASSERT_STREQ(array_sized, "12345");
}
