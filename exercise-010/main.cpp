#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "myvector.hpp"

using namespace tfe24;

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

    /*
    {
        MyVector vec;
    }

    MyVector vec2(27);
    fmt::println("Hello exercise number 3 after Vector");
    */

    MyVector<int> v;

    // Elemente hinzufügen
    for (int i = 0; i < 10; ++i)
        v.push_back(i * 10);

    v.print(); // Ausgabe mit fmt::print

    // Deep-Copy-Test
    MyVector<int> copy = v;
    copy[0] = 999;

    fmt::print("Original[0]: {}\n", v[0]);
    fmt::print("Kopie[0]:    {}\n", copy[0]);

    // Performance-Test
    MyVector<int> perf;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i)
        perf.push_back(i);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    fmt::print("Zeit für 1 Mio. push_backs: {:.6f} s\n", diff.count());


    return 0; /* exit gracefully*/
}
