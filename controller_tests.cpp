//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include <algorithm>
#include <deque>
#include <iterator>
#include <numeric>

#include "Controller.h"

static constexpr int32_t DEFAULT_FLOOR = 1;

TEST(ControllerTest, QueueConstructor)
{
    Elevator elevator(DEFAULT_FLOOR);
    std::deque floors{ 1, 2, 3, 4 };
    const auto target = std::make_unique<Controller>(elevator, floors);
    EXPECT_EQ(target->GetFloorsToVisit(), floors);
    EXPECT_EQ(&target->GetElevator(), &elevator);
}

TEST(ControllerTest, Execute)
{
    Elevator elevator(DEFAULT_FLOOR);
    std::deque floors{ 3, 1, 4, 2 };
    const auto target = std::make_unique<Controller>(elevator, floors);
    target->Execute();
    auto expectedFloors = std::deque{ DEFAULT_FLOOR };
    std::ranges::move(floors, std::back_inserter(expectedFloors));
    EXPECT_EQ(target->GetElevator().GetVisitedFloors(), expectedFloors);

    auto expectedTravelTime = 0s;
    int32_t previousFloor = DEFAULT_FLOOR;
    for (auto floor : floors)
    {
        expectedTravelTime +=
            std::abs(floor - previousFloor) * Elevator::TravelTimeForSingleFloor;
        previousFloor = floor;
    }
    EXPECT_EQ(target->GetElevator().GetTotalTravelTime(), expectedTravelTime);
}
