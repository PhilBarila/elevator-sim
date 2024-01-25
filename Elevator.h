//
// Created by phil on 1/23/2024.
//

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <chrono>
#include <cstdint>
#include <deque>

using std::chrono_literals::operator ""s;

class Elevator
{
public:
    Elevator() = delete;
    explicit Elevator(int32_t floor);
    void Move(int32_t floor);
    [[nodiscard]] int32_t GetCurrentFloor() const;
    [[nodiscard]] std::chrono::seconds GetTotalTravelTime() const;
    [[nodiscard]] const std::deque<int32_t>& GetVisitedFloors() const;
    static constexpr std::chrono::seconds TravelTimeForSingleFloor = 10s;
private:
    int32_t m_CurrentFloor{1};
    std::chrono::seconds m_TotalTravelTime{};
    std::deque<int32_t> m_VisitedFloors{};
};

#endif //ELEVATOR_H
