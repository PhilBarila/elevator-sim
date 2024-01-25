//
// Created by phil on 1/24/2024.
//

#include <gtest/gtest.h>

#include "OutputFormatter.h"

TEST(OutputFormatterTest, GetVisitedFloorString)
{
    const std::deque floors{2, 9, 1, 32};
    const std::string actual{OutputFormatter::GetVisitedFloorsString(floors)};
    const std::string expected{"2,9,1,32"};
    EXPECT_EQ(actual, expected);
}
