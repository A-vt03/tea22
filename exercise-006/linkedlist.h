#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

// Definition der Knotenstruktur
typedef struct ListNode {
    unsigned int data;          // Daten des Knotens
    struct ListNode* pNext;     // Zeiger auf den nächsten Knoten
} ListNode_t;

// Definition der Listenstruktur
typedef struct List {
    ListNode_t* pHead;          // Zeiger auf den Kopf der Liste
    ListNode_t* pTail;          // Zeiger auf das Ende der Liste
    unsigned int size;          // Anzahl der Knoten in der Liste
} List_t;

// Funktionen
List_t* CreateList();                                  // Erstellt eine neue Liste
ListNode_t* NewListNode(unsigned int data);            // Erstellt einen neuen Knoten
void FreeListNode(ListNode_t* elem);                   // Gibt Speicher eines Knotens frei
int InsertIntoLinkedList(List_t* list, unsigned int data, unsigned int position); // Fügt ein Element ein
int RemoveFromLinkedList(List_t* list, unsigned int position);                    // Entfernt ein Element
void IterateLinkedList(const List_t* list);            // Gibt die gesamte Liste aus
void FreeLinkedList(List_t* list);                     // Gibt die gesamte Liste frei

#endif // LINKEDLIST_H
