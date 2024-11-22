#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// Funktion: Erstellt eine neue Liste
List_t* CreateList() {
    List_t* list = (List_t*)malloc(sizeof(List_t));
    if (!list) {
        fprintf(stderr, "Fehler: Speicher konnte nicht reserviert werden.\n");
        return NULL;
    }
    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;
    return list;
}

// Funktion: Erstellt einen neuen Knoten
ListNode_t* NewListNode(unsigned int data) {
    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (!node) {
        fprintf(stderr, "Fehler: Speicher konnte nicht reserviert werden.\n");
        return NULL;
    }
    node->data = data;
    node->pNext = NULL;
    return node;
}

// Funktion: Gibt den Speicher eines Knotens frei
void FreeListNode(ListNode_t* elem) {
    if (elem) {
        free(elem);
    }
}

// Funktion: Fügt ein Element in die Liste ein
int InsertIntoLinkedList(List_t* list, unsigned int data, unsigned int position) {
    if (!list || position > list->size) {
        return -1; // Fehler: Ungültige Position oder Liste existiert nicht
    }

    ListNode_t* newNode = NewListNode(data);
    if (!newNode) return -1;

    if (position == 0) { // Am Anfang einfügen
        newNode->pNext = list->pHead;
        list->pHead = newNode;
        if (list->size == 0) list->pTail = newNode; // Wenn die Liste leer war, pTail aktualisieren
    } else { // An anderer Stelle einfügen
        ListNode_t* current = list->pHead;
        for (unsigned int i = 0; i < position - 1; ++i) {
            current = current->pNext;
        }
        newNode->pNext = current->pNext;
        current->pNext = newNode;
        if (newNode->pNext == NULL) {
            list->pTail = newNode; // Falls am Ende eingefügt, pTail aktualisieren
        }
    }

    list->size++;
    return 0;
}

// Funktion: Entfernt ein Element aus der Liste
int RemoveFromLinkedList(List_t* list, unsigned int position) {
    if (!list || position >= list->size) {
        return -1; // Fehler: Ungültige Position oder Liste existiert nicht
    }

    ListNode_t* toDelete = NULL;

    if (position == 0) { // Am Anfang entfernen
        toDelete = list->pHead;
        list->pHead = list->pHead->pNext;
        if (list->size == 1) {
            list->pTail = NULL; // Falls die Liste nur ein Element hatte
        }
    } else { // Entfernen an anderer Position
        ListNode_t* current = list->pHead;
        for (unsigned int i = 0; i < position - 1; ++i) {
            current = current->pNext;
        }
        toDelete = current->pNext;
        current->pNext = toDelete->pNext;
        if (current->pNext == NULL) {
            list->pTail = current; // Falls der letzte Knoten entfernt wurde
        }
    }

    FreeListNode(toDelete);
    list->size--;
    return 0;
}

// Funktion: Gibt die gesamte Liste aus
void IterateLinkedList(const List_t* list) {
    if (!list) {
        fprintf(stderr, "Fehler: Liste ist NULL.\n");
        return;
    }

    ListNode_t* current = list->pHead;
    while (current) {
        printf("%u -> ", current->data);
        current = current->pNext;
    }
    printf("NULL\n");
}

// Funktion: Gibt die gesamte Liste frei
void FreeLinkedList(List_t* list) {
    if (!list) return;

    ListNode_t* current = list->pHead;
    while (current) {
        ListNode_t* toDelete = current;
        current = current->pNext;
        FreeListNode(toDelete);
    }

    free(list);
}
