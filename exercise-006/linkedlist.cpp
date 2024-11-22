#include "linkedlist.h"
#include <stdlib.h> // needed for malloc/free

ListNode_t* NewListNode(void) {
    ListNode_t* pTemp = (ListNode_t*) malloc(sizeof(ListNode_t));
    if(pTemp != NULL) {
        pTemp->pNext = NULL;
        pTemp->data = 0;
    }
    return pTemp;

}
void FreeListNode(ListNode_t* elem) {
    if(elem != NULL) {
        free(elem);
    }
}

List_t* NewList(void) {
    List_t* pTempList = (List_t*) malloc(sizeof(List_t));
    if(pTempList != NULL) {
        pTempList->pHead = NULL;
        pTempList->pTail = NULL;
        pTempList->size = 0;
    }
    return pTempList;
}

void FreeList(List_t* list)  {
    if(list != NULL) {
        // Walk through the list and delete each element
        
        // insert your Code here....

        // free the remaining part
        free(list);
    }
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    // insert your Code here....
    return 0;
}

int InsertIntoLinkedListAfterNode(List_t* list, 
    ListNode_t* node /* the node we insert the element into */, 
    ListNode_t* elem /* the node to be inserted */) {

    // insert your Code here....
    return 0;
}

int RemoveFromList(List_t* list, ListNode_t* elem) {
    // insert your Code here....
    return 0;
}
ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    // insert your Code here....
    return NULL;
}