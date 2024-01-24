//
// Created by phil on 1/24/2024.
//

#include "Controller.h"

Controller::Controller(std::deque<int32_t>& floorsToVisit)
: m_FloorsToVisit(floorsToVisit)
{
}

std::deque<int32_t> Controller::FloorsToVisit() const
{
    return m_FloorsToVisit;
}
