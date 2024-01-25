//
// Created by phil on 1/24/2024.
//

#include "Controller.h"

#include <memory>

#include "Elevator.h"

Controller::Controller(Elevator& elevator, const std::deque<int32_t>& floorsToVisit)
: m_Elevator(elevator), m_FloorsToVisit(floorsToVisit)
{
}

const Elevator& Controller::GetElevator() const
{
    return m_Elevator;
}

std::deque<int32_t> Controller::GetFloorsToVisit() const
{
    return m_FloorsToVisit;
}

void Controller::Execute()
{
    for (auto floor : m_FloorsToVisit)
    {
        m_Elevator.Move(floor);
    }
}
