#include "gtest/gtest.h"
#include "hello.h"

TEST(Hello, isStringCorrect) {
    EXPECT_EQ("Hello World", hello());
}