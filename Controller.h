//
// Created by phil on 1/24/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdint>
#include <deque>

#include "Elevator.h"

class Controller
{
public:
    Controller() = delete;
    explicit Controller(Elevator& elevator, const std::deque<int32_t>& floorsToVisit);

    [[nodiscard]] const Elevator& GetElevator() const;
    [[nodiscard]] std::deque<int32_t> GetFloorsToVisit() const;
    void Execute();

private:
    Elevator& m_Elevator;
    std::deque<int32_t> m_FloorsToVisit;
};

#endif //CONTROLLER_H
