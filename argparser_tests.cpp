//
// Created by phil on 1/24/2024.
//

#include <gtest/gtest.h>

#include "ArgParser.h"

TEST(ArgParserTest, Constructor)
{
    const auto target = std::make_unique<ArgParser>();
    EXPECT_NE(target.get(), nullptr);
}
