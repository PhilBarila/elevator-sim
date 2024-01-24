//
// Created by phil on 1/23/2024.
//

#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <chrono>

using namespace std::chrono_literals;

class Elevator {
public:
    Elevator() = default;
    explicit Elevator(int32_t floor);
    void Move(int32_t floor);
    [[nodiscard]] int32_t CurrentFloor() const;
    std::chrono::seconds TotalTravelTime();
    static constexpr std::chrono::seconds TravelTimeForSingleFloor = 10s;
private:
    int32_t m_CurrentFloor;
    std::chrono::seconds m_TotalTravelTime;
};

#endif //ELEVATOR_H
