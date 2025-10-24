#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include "point.hpp"

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

    Point p1(2,3);  
    p1.print();

    p1.move(1,-1);   
    p1.print();

    Point p2;     
    p2.print();

    // Zusatz 

    Point a(0, 0);
    Point b(3, 4);

    a.print();
    b.print();

    double d = a.distance_to(b);
    fmt::print("Abstand a–b = {:.3f}\n", d);

    b.move(4, 3);  
    fmt::print("Abstand a–b = {:.3f}\n", a.distance_to(b));

    return 0; /* exit gracefully*/
}
