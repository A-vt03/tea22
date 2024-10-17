#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};

    // Variable neu erstellen (deklarieren) mit dem Datentyp unsigned char (0...255; 2^8)
    // Dieser Variable weißen wir den Wert 20 zu  (initialisieren)
    unsigned char count = 20; 

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        // Neue Option hinzugefügt, mit dem Parametername "-c, --count"
        // In der Variable count (von oben) wird der wert gespeichert
        // "The count" wird in der -h/ --help als Hilfestellung angezeigt
        app.add_option("-c,--count", count, "The count");
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
    fmt::print("My count, {}\n", count);

    /* INSERT YOUR CODE HERE */
    // Deklarieren eines leeren Vektors vom Typ int
    std::vector<int> randomVector;
    // Eine for-Schleife, die von 0 bis zu der Variablen `count` läuft.
    // In jeder Iteration wird der aktuelle Wert von i als Zufallszahl (hier einfach `i` selbst) verwendet
    // und in den Vektor eingefügt.
    for (int i=0; i<count;i++)
    {
        // Generiere eine Nummer zwischen 0 und 100
        int randomNumber = rand() %101;
        // Fügen der "zufälligen" Zahl zum Vektor hinzu
        randomVector.push_back(randomNumber);
    }
    // Deklarieren eines Iterators für den Vektor vom Typ `std::vector<int>::iterator`
    std::vector<int>::iterator iter;
    // Eine for-Schleife, die den Vektor durchläuft
    // Der Iterator startet bei `randomVector.begin()` und endet bei `randomVector.end()`
    for (iter = randomVector.begin(); iter != randomVector.end(); iter++) {
        fmt::print("Vector value: {}\n", *iter);
    }


    return 0; /* exit gracefully*/
}