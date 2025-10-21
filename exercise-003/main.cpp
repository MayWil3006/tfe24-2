#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

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


    return 0; /* exit gracefully*/
}
