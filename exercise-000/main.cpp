#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"


    // Teil 3: Funktionen mit Zeigern //////////

    void ChangeValueByParameter(int value){
        value = 99;
        fmt::print("Der neue Wert der Variablen ist {}\n", value);
    }

    void ChangeValueByPointer(int* ptr){
        *ptr = 77;
        fmt::print("Der neue Wert der Variablen ist {}\n", *ptr);
    }

auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello world, {}!\n", tfe24::PROJECT_NAME);

    // Teil 1: Zeiger Grundlagen //////////
    int x = 10;
    int* p = &x;   // & ist der Adressoperator
    fmt::print("Der Wert von x ist {}\n", x);
    fmt::print("Die Adresse von x ist {}\n", fmt::ptr(&x));

    fmt::print("Wert auf den p zeigt ist {}\n", *p);  // Um auf den Inhalt von p zuzugreifen braucht man den Dereferenzieroperator *
    fmt::print("Die Adresse die p enthält ist {}\n", fmt::ptr(p));

    *p = 42;
    fmt::print("Der neue Wert von x ist {}\n", x);
    fmt::print("Der neue Wert auf den p zeigt ist {}\n", *p);

    // Teil 2: Dynamische Speicherverwaltung //////////

    double* d = new double(3.1415);
    fmt::print("Der Wert von d ist {}\n", *d);  
    fmt::print("Die Adresse der Variablen ist {}\n", fmt::ptr(d));
    delete d; 

    // Teil 3: Funktionen mit Zeigern //////////

    int y = 5;
    fmt::print("Vor der Änderung ist y = {}\n", y); // 5
    ChangeValueByParameter(y); // 99
    fmt::print("Der veränderte Wert ist y = {}\n", y); // 5 Da das Orginal unverändert bleibt und nur die Kopie verändert wird

    fmt::print("Vor der Änderung ist y = {}\n", y); // 5
    ChangeValueByPointer(&y); // 77
    fmt::print("Der veränderte Wert ist y = {}\n", y);  // 77 Da die Adresse übergeben wird und somit das Orginal verändert wird  


    return 0; /* exit gracefully*/
}
