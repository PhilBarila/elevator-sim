//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include "Elevator.h"

static constexpr int32_t DEFAULT_FLOOR = 1;

TEST(ElevatorTest, InitialFloorConstruction)
{
    constexpr int32_t initialFloor = 42;
    const auto target = std::make_unique<Elevator>(initialFloor);
    EXPECT_NE(target.get(), nullptr);
    EXPECT_EQ(target->GetCurrentFloor(), initialFloor);
    EXPECT_EQ(target->GetTotalTravelTime(), 0s);
    const auto expectedFloors = std::deque{initialFloor};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}

TEST(ElevatorTest, MoveToFloorOneFromOne)
{
    const auto target = std::make_unique<Elevator>(DEFAULT_FLOOR);
    constexpr int32_t floor = 1;
    target->Move(floor);
    EXPECT_EQ(target->GetCurrentFloor(), floor);
    EXPECT_EQ(target->GetTotalTravelTime(), 0s);
    const auto expectedFloors = std::deque{DEFAULT_FLOOR};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}

TEST(ElevatorTest, MoveToFloorTenFromOne)
{
    const auto target = std::make_unique<Elevator>(1);
    constexpr int32_t floor = 10;
    target->Move(floor);
    EXPECT_EQ(target->GetCurrentFloor(), floor);
    constexpr std::chrono::seconds expectedTravelTime =
        Elevator::TravelTimeForSingleFloor * (floor - DEFAULT_FLOOR);
    EXPECT_EQ(target->GetTotalTravelTime(), expectedTravelTime);
    const auto expectedFloors = std::deque{DEFAULT_FLOOR, floor};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}

TEST(ElevatorTest, MoveToFloorTenFromInitial)
{
    constexpr int32_t initialFloor = 42;
    const auto target = std::make_unique<Elevator>(initialFloor);
    constexpr int32_t floor = 10;
    target->Move(floor);
    EXPECT_EQ(target->GetCurrentFloor(), floor);
    constexpr int32_t distance = std::abs(initialFloor - floor);
    constexpr std::chrono::seconds expectedTravelTime =
        distance * Elevator::TravelTimeForSingleFloor;
    EXPECT_EQ(target->GetTotalTravelTime(),  expectedTravelTime);
    const auto expectedFloors = std::deque{initialFloor, floor};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}

TEST(ElevatorTest, VisitMultipleFloors)
{
    const auto target = std::make_unique<Elevator>(DEFAULT_FLOOR);
    constexpr int32_t firstFloor = 10;
    constexpr int32_t secondFloor = 3;
    constexpr int32_t distance =
        firstFloor - DEFAULT_FLOOR + std::abs(firstFloor - secondFloor);
    constexpr std::chrono::seconds expectedTravelTime =
        distance * Elevator::TravelTimeForSingleFloor;
    target->Move(firstFloor);
    target->Move(secondFloor);
    EXPECT_EQ(target->GetCurrentFloor(), secondFloor);
    EXPECT_EQ(target->GetTotalTravelTime(), expectedTravelTime);
    const auto expectedFloors = std::deque{DEFAULT_FLOOR, firstFloor, secondFloor};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}

TEST(ElevatorTest, VisitMultipleFloorsFromInitial)
{
    constexpr int32_t initialFloor = 42;
    const auto target = std::make_unique<Elevator>(initialFloor);
    constexpr int32_t firstFloor = 10;
    constexpr int32_t secondFloor = 17;
    constexpr int32_t distance =
        std::abs(initialFloor - firstFloor) + std::abs(firstFloor - secondFloor);
    constexpr std::chrono::seconds expectedTravelTime =
        distance * Elevator::TravelTimeForSingleFloor;
    target->Move(firstFloor);
    target->Move(secondFloor);
    EXPECT_EQ(target->GetCurrentFloor(), secondFloor);
    EXPECT_EQ(target->GetTotalTravelTime(), expectedTravelTime);
    const auto expectedFloors = std::deque{initialFloor, firstFloor, secondFloor};
    EXPECT_EQ(target->GetVisitedFloors(), expectedFloors);
}
