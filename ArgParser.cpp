//
// Created by phil on 1/24/2024.
//

#include "ArgParser.h"

#include <cstdint>
#include <deque>
#include <ranges>
#include <sstream>

std::tuple<int32_t, std::deque<int32_t>>
ArgParser::Parse(const std::vector<std::string_view>& args)
{
    int32_t startFloor {};
    std::deque<int32_t> floors{};
    for (const auto arg : args)
    {
        const std::string startPrefix{"start="};
        const std::string floorPrefix{"floor="};
        if (arg.starts_with(startPrefix))
        {
            std::string floor{arg.substr(startPrefix.size())};
            startFloor = std::stoi(floor);
        }
        else if (arg.starts_with(floorPrefix))
        {
            std::stringstream floorSpec{std::string{arg.substr(floorPrefix.size())}};
            std::string floor;
            while (std::getline(floorSpec, floor, ','))
            {
                floors.emplace_back(std::stoi(floor));
            }
        }
    }
    return std::make_tuple(startFloor, floors);
}
