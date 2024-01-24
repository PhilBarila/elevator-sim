//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include "Elevator.h"

TEST(ElevatorTest, BasicConstruction)
{
    const auto target = std::make_unique<Elevator>();
    EXPECT_NE(target.get(), nullptr);
    EXPECT_EQ(target->CurrentFloor(), 0);
    EXPECT_EQ(target->TotalTravelTime(), 0s);
}

TEST(ElevatorTest, InitialFloorConstruction)
{
    constexpr int32_t initialFloor = 42;
    const auto target = std::make_unique<Elevator>(initialFloor);
    EXPECT_NE(target.get(), nullptr);
    EXPECT_EQ(target->CurrentFloor(), initialFloor);
    EXPECT_EQ(target->TotalTravelTime(), 0s);
}

TEST(ElevatorTest, MoveOneFloorTest)
{
    const auto target = std::make_unique<Elevator>();
    constexpr int32_t floor = 1;
    target->Move(floor);
    EXPECT_EQ(target->CurrentFloor(), floor);
    EXPECT_EQ(target->TotalTravelTime(), Elevator::TravelTimeForSingleFloor);
}

TEST(ElevatorTest, MoveToFloorTenTest)
{
    const auto target = std::make_unique<Elevator>();
    constexpr int32_t floor = 10;
    target->Move(floor);
    EXPECT_EQ(target->CurrentFloor(), floor);
    EXPECT_EQ(
        target->TotalTravelTime(), Elevator::TravelTimeForSingleFloor * floor
        );
}

TEST(ElevatorTest, MoveToFloorTenFromInitialTest)
{
    constexpr int32_t initialFloor = 42;
    const auto target = std::make_unique<Elevator>(initialFloor);
    constexpr int32_t floor = 10;
    target->Move(floor);
    EXPECT_EQ(target->CurrentFloor(), floor);
    constexpr int32_t distance = std::abs(initialFloor - floor);
    constexpr std::chrono::seconds expectedTravelTime =
        distance * Elevator::TravelTimeForSingleFloor;
    EXPECT_EQ(target->TotalTravelTime(),  expectedTravelTime);
}
