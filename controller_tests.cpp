//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include <deque>

#include "Controller.h"

TEST(ControllerTest, BasicConstruction)
{
    const auto target = std::make_unique<Controller>();
    EXPECT_NE(target.get(), nullptr);
}

TEST(ControllerTest, QueueConstructor)
{
    std::deque floors{1,2,3,4};
    const auto target = std::make_unique<Controller>(floors);
    EXPECT_EQ(target->FloorsToVisit(), floors);
}
