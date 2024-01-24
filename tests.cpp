//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include "Elevator.h"

TEST(ElevatorTest, BasicConstruction)
{
    auto target = std::make_unique<Elevator>();
    EXPECT_NE(nullptr, target.get());
}


