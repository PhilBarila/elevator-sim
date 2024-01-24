//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include "Elevator.h"

TEST(ElevatorTest, BasicConstruction)
{
    auto target = std::make_unique<Elevator>();
    EXPECT_NE(target.get(), nullptr);
    EXPECT_EQ(target->CurrentFloor(), 0);
    EXPECT_EQ(target->TotalTravelTime(), 0s);
}

TEST(ElevatorTest, MoveTest)
{
    auto target = std::make_unique<Elevator>();
    uint32_t floor = 1;
    target->Move(floor);
    EXPECT_EQ(target->CurrentFloor(), floor);
    EXPECT_EQ(target->TotalTravelTime(), Elevator::TravelTimeForSingleFloor);
}
