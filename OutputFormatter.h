//
// Created by phil on 1/24/2024.
//

#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include <cstdint>
#include <deque>
#include <string>

class OutputFormatter
{
public:
    static std::string GetVisitedFloorsString(const std::deque<int32_t>& floors);
};

#endif //OUTPUTFORMATTER_H
