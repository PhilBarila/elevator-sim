//
// Created by phil on 1/24/2024.
//

#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <deque>
#include <string_view>
#include <tuple>
#include <vector>

class ArgParser
{
public:
    static std::tuple<int, std::deque<int>> Parse(const std::vector<std::string_view>& args);
};

#endif //ARGPARSER_H
