//
// Created by phil on 1/23/2024.
//

#include "Elevator.h"

Elevator::Elevator(int32_t floor)
: m_CurrentFloor(floor)
{
    m_VisitedFloors.emplace_back(floor);
}

void Elevator::Move(const int32_t floor)
{
    if (floor != m_CurrentFloor)
    {
        m_TotalTravelTime += TravelTimeForSingleFloor * std::abs(floor - m_CurrentFloor);
        m_CurrentFloor = floor;
        m_VisitedFloors.push_back(floor);
    }
}

int32_t Elevator::GetCurrentFloor() const
{
    return m_CurrentFloor;
}

std::chrono::seconds Elevator::GetTotalTravelTime() const
{
    return m_TotalTravelTime;
}

const std::deque<int32_t>& Elevator::GetVisitedFloors() const
{
    return m_VisitedFloors;
}
