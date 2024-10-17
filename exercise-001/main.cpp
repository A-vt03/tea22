#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <algorithm> // für std::sort
#include <iostream>  // für std::cin

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};

    unsigned char count = 20; 

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "The count");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("My count, {}\n", count);

    // Deklarieren eines Vektors vom Typ int
    std::vector<int> randomVektor;

    // Eine for-Schleife, die von 0 bis zu der Variablen `count` läuft.
    // In jeder Iteration wird der aktuelle Wert von i als Zufallszahl verwendet
    // und in den Vektor eingefügt.
    for (int i = 0; i < count; i++)
    {
         // Zufallszahl zwischen 0 und 100
        int randomNumber = rand() % 101; 
        randomVektor.push_back(randomNumber);
    }

    // Sortiere den gesamten Vektor
    std::sort(randomVektor.begin(), randomVektor.end());

    // Ausgabe des sortierten Vektors
    for (const auto &val : randomVektor)
    {
        fmt::print("Sorted vector value: {}\n", val);
    }

    return 0; /* exit gracefully */
}