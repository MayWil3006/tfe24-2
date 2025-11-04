#include <fmt/chrono.h>
#include <fmt/format.h>

#include <nlohmann/json.hpp>

#include "CLI/CLI.hpp"
#include "config.h"

#include "point.hpp"

// for convenience
using json = nlohmann::json;

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    Point<int> p1(2, 3);
    p1.print();
    p1.move(5, 4);
    p1.print();

    Point<int> p2(4, 6);
    p2.print();
    p2.move(1, 3);
    p2.print();

    auto dist = p1.distance_to(p2);
    fmt::print("Distance between p1 and p2: {:.2f}\n", dist);

    if (p1 == p2)
        fmt::print("p1 == p2: true\n");
    else
        fmt::print("p1 == p2: false\n");

    return 0; /* exit gracefully*/
}
