//
// Created by phil on 1/24/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <cstdint>
#include <deque>

class Controller {
public:
    Controller() = default;
    explicit Controller(std::deque<int32_t>& floorsToVisit);
    [[nodiscard]] std::deque<int32_t> FloorsToVisit() const;
private:
    std::deque<int32_t> m_FloorsToVisit;
};

#endif //CONTROLLER_H
