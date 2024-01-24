//
// Created by phil on 1/23/2024.
//

#include "Elevator.h"

Elevator::Elevator(int32_t floor)
: m_CurrentFloor(floor)
{
}

void Elevator::Move(int32_t floor)
{
    m_TotalTravelTime += TravelTimeForSingleFloor * std::abs(floor - m_CurrentFloor);
    m_CurrentFloor = floor;
}

int32_t Elevator::GetCurrentFloor() const
{
    return m_CurrentFloor;
}

std::chrono::seconds Elevator::GetTotalTravelTime() const
{
    return m_TotalTravelTime;
}
