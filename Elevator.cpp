//
// Created by phil on 1/23/2024.
//

#include "Elevator.h"

Elevator::Elevator(int32_t floor)
: m_CurrentFloor(floor)
, m_TotalTravelTime()
{
}

void Elevator::Move(int32_t floor)
{
    m_TotalTravelTime += TravelTimeForSingleFloor * std::abs(floor - m_CurrentFloor);
    m_CurrentFloor = floor;
}

int32_t Elevator::CurrentFloor() const
{
    return m_CurrentFloor;
}

std::chrono::seconds Elevator::TotalTravelTime()
{
    return m_TotalTravelTime;
}
