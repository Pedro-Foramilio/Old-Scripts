#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *prev;
    LinkedNode *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    //if List = 1 node then first == last
    LinkedNode *first;
    LinkedNode *last;
};

void printLinkedList(LinkedList *list) {
    LinkedNode *current = list->first;
    int counter = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", counter, current->data);
        counter++;
        current = current->next;
    }
}

LinkedList *createLinkedList(int firstValue) {
    LinkedNode *node1 = malloc(sizeof(LinkedNode));

    node1->data = firstValue;
    node1->prev = NULL;
    node1->next = NULL;

    LinkedList *list = malloc(sizeof(LinkedList));
    list->first = node1;
    list->last = node1;

    return list;
}

LinkedList *insertLastPosition(LinkedList *list, int value) {
    LinkedNode *newNode = malloc(sizeof(LinkedNode));
    newNode->data = value;
    
    LinkedNode *lastNode = list->last;
    lastNode->next = newNode;
    newNode->prev = lastNode;
    newNode->next = NULL;

    list->last = newNode;
    return list;
}

LinkedList *insertPosition(LinkedList *list, int position, int value) {
    if (position < 0) return list;

    LinkedNode *newNode = malloc(sizeof(LinkedNode));
    newNode->data = value;
    
    int counter = 0;
    LinkedNode *current = list->first;
    while (counter != position && current != NULL) {
        current = current->next;
        counter++;
    }

    //last position
    if (counter == position && current == NULL) {
        return insertLastPosition(list, value);
    }

    newNode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newNode;
        
    current->prev = newNode;
    newNode->next = current;

    return list;
}

int main() {
    LinkedList *myList = createLinkedList(12);
    printLinkedList(myList);
    printf("---------\n");
    myList = insertLastPosition(myList, 15);
    printLinkedList(myList);
    printf("---------\n");
    myList = insertLastPosition(myList, 17);
    printLinkedList(myList);
    printf("---------\n");

    myList = insertPosition(myList, 0, 10);
    printLinkedList(myList);
    printf("---------\n");

    myList = insertPosition(myList, 2, 100);
    printLinkedList(myList);
    printf("---------\n");

    return 0;
}


