//
// Created by phil on 1/24/2024.
//

#include <gtest/gtest.h>

#include "ArgParser.h"

TEST(ArgParserTest, Parse)
{
    const auto [start, floors] = ArgParser::Parse({"start=12", "floor=2,9,1,32"});
    EXPECT_EQ(start, 12);
    const auto expectedFloors = std::deque{ 2, 9, 1, 32 };
    EXPECT_EQ(floors, expectedFloors);
}
