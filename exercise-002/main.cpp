#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

int globalVar = 1;

void foo() { fmt::print("Hello from foo!\\n"); }

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
    fmt::print("Hello, {}!\n\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    fmt::print("Wert der Globalen Variablen globalVar = {}\n", globalVar);
    fmt::print("Adresse der Globalen Variablen globalVar = {}\n", static_cast<const void*>(&globalVar));
    fmt::print("Beobachtung: Globale Variablen liegen im Data-Segment\n\n");

    int localVar = 2;
    fmt::print("Wert der Lokalen Variablen localVar = {}\n", localVar);
    fmt::print("Adresse der Lokalen Variablen localVar = {}\n", static_cast<const void*>(&localVar));
    fmt::print("Beobachtung: Lokale Variablen liegen im Stack-Segment\n\n");

    int* heapVar = new int(3);
    fmt::print("Wert der Heap Variablen heapVar = {}\n", *heapVar);
    fmt::print("Adresse der Heap Variablen heapVar = {}\n", static_cast<const void*>(heapVar));
    delete heapVar;
    fmt::print("Beobachtung: Heap Variablen liegen im Heap-Segment\n\n");

    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));
    fmt::print("Beobachtung: Funktionen liegen im Code-Segment\n");

    /*
    Lokale Variablen werden automatisch im Stack verwaltet und man kann schnell auf sie zugreifen.
    Dynamische Objekte im Heap müssen manuell verwaltet werden, was Auswirkungen auf Speicherverbrauch, 
    Laufzeitverhalten und Programmstabilität hat.

    Referenzen zeigen auf denselben Speicherort ohne selbst Speicher zu belegen.
    Zeiger speichern Adressen und erlauben direkten Zugriff auf die Speicherbereiche.
    */

    return 0; /* exit gracefully*/
}
