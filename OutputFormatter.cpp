//
// Created by phil on 1/24/2024.
//

#include <sstream>

#include "OutputFormatter.h"

std::string OutputFormatter::GetVisitedFloorsString(const std::deque<int32_t>& floors)
{
    std::stringstream ss;
    for (const auto floor : floors)
    {
        ss << floor << ",";
    }
    // Remove the last comma
    const auto&& str = ss.str();
    return str.substr(0, str.length() - 1);
}
