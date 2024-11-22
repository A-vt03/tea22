#include <fmt/format.h>
#include "linkedlist.h"

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    // Erstelle eine neue Liste
    List_t* list = CreateList();
    if (!list) {
        fmt::print(stderr, "Fehler: Liste konnte nicht erstellt werden.\n");
        return -1;
    }

    // Elemente hinzufügen
    fmt::print("Füge Elemente zur Liste hinzu...\n");
    InsertIntoLinkedList(list, 10, 0); // [10]
    InsertIntoLinkedList(list, 20, 1); // [10, 20]
    InsertIntoLinkedList(list, 30, 2); // [10, 20, 30]
    InsertIntoLinkedList(list, 15, 1); // [10, 15, 20, 30]

    // Liste ausgeben
    fmt::print("Liste nach dem Einfügen:\n");
    IterateLinkedList(list);

    // Element entfernen
    fmt::print("Entferne ein Element aus der Liste...\n");
    RemoveFromLinkedList(list, 1); // Entferne das zweite Element (15)

    // Liste erneut ausgeben
    fmt::print("Liste nach dem Entfernen:\n");
    IterateLinkedList(list);

    // Speicher freigeben
    fmt::print("Gebe den Speicher der Liste frei...\n");
    FreeLinkedList(list);

    fmt::print("Programm beendet erfolgreich.\n");
    return 0;
}
