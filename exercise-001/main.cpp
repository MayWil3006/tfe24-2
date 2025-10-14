#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value) {
    value = 99;
    fmt::print("In der Funktion changeValueByParameter ist value = {}\n", value);
}

void changeValueByReference(int& ref) {
    ref = 77;
    fmt::print("In der Funktion changeValueByReference ist ref = {}\n", ref);
}

auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tfe24::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    int x = 10;
    int y = 5;
    int& r = x;
    fmt::print("Alte Werte: \n");
    fmt::print("Der Wert von x ist: {}\n", x);
    fmt::print("Der Wert von r ist: {}\n", r);

    r = 42;

    fmt::print("Neue Werte: \n");
    fmt::print("Der neue Wert von x ist: {}\n", x);
    fmt::print("Der neue Wert von r ist: {}\n\n", r);


    changeValueByParameter(x);
    fmt::print("Auswirkungen auf x durch changeValueByParameter: x = {}\n", x);
    changeValueByReference(x);
    fmt::print("Auswirkungen auf x durch changeValueByReference: x = {}\n\n", x);

    fmt::print("Ursprünglicher Wert von y = {}\n", y);
    changeValueByParameter(y);
    fmt::print("Auswirkungen auf y durch changeValueByParameter: y = {}\n", y);
    fmt::print("Ursprünglicher Wert von y = {}\n", y);
    changeValueByReference(y);
    fmt::print("Nach der Funktion changeValueByReference: y = {}\n", y);

    return 0; /* exit gracefully*/
}
