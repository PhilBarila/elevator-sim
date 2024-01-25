#include <iostream>

#include "ArgParser.h"
#include "Controller.h"
#include "Elevator.h"
#include "OutputFormatter.h"

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 1; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }
    auto floors = ArgParser::Parse(args);
    Elevator elevator(std::get<0>(floors));
    Controller controller(elevator, std::get<1>(floors));
    controller.Execute();
    const auto visited{
        OutputFormatter::GetVisitedFloorsString(elevator.GetVisitedFloors())
        };
    std::cout << elevator.GetTotalTravelTime() << " " << visited << std::endl;
    return 0;
}
