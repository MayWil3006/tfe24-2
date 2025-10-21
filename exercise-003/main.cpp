#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <vector>
#include <random> 

#include <algorithm>
#include <chrono> 

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};
    int count = 20;

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));

    // Optionen hinzufügen und count übergeben. Außerdem Beschreibung der Option (wird in --help angezeigt)
        app.add_option("-c,--count", count, "Anzahl Wiederholungen");

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

    fmt::print("Der übergebene Wert ist: {}\n", count);

    std::vector<int> values(static_cast<std::size_t>(count));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::generate(values.begin(), values.end(), [&]{ return dist(gen); });

    fmt::print("Zufallswerte:");
    for (int v : values) fmt::print(" {}", v);
    fmt::print("\n");

    // Zeit messen
    auto t0 = std::chrono::steady_clock::now();
    std::sort(values.begin(), values.end());
    auto t1 = std::chrono::steady_clock::now();

    // Dauer in Mikrosekunden
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();

    fmt::print("Sortierdauer: {} µs\n", us);


    return 0; /* exit gracefully*/
}
