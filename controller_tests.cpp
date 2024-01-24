//
// Created by phil on 1/23/2024.
//

#include <gtest/gtest.h>

#include <deque>

#include "Controller.h"

static constexpr int32_t DEFAULT_FLOOR = 1;

TEST(ControllerTest, QueueConstructor)
{
    Elevator elevator(DEFAULT_FLOOR);
    std::deque floors{1,2,3,4};
    const auto target = std::make_unique<Controller>(elevator, floors);
    EXPECT_EQ(target->GetFloorsToVisit(), floors);
    EXPECT_EQ(&target->GetElevator(), &elevator);
}

TEST(ControllerTest, Execute)
{
    Elevator elevator(DEFAULT_FLOOR);
    std::deque floors{1,2,3,4};
    const auto target = std::make_unique<Controller>(elevator, floors);
    EXPECT_EQ(target->GetFloorsToVisit(), floors);
}
