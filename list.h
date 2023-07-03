#include <stdio.h>
#include <stdlib.h>

/*
 * This header file defines a Node structure and functions for a circular linked list. 
 *
 * A Node structure represents a node in a circular linked list, containing an integer data field and a pointer to the next Node in the list.
 */

typedef struct Node {
    int data;              /* Integer data for the node. */
    struct Node* next;     /* Pointer to the next node in the list. */
} Node;

/*
 * createNode function creates a new node in the list.
 * Inputs: int data - The data for the new node.
 * Outputs: Node* - A pointer to the new node.
 */
Node* createNode(int data);

/*
 * insertNode function inserts a new node into the list.
 * If the list is empty, it creates a new list.
 * Inputs: Node* last - A pointer to the last node in the list.
 *         int data - The data for the new node.
 * Outputs: Node* - A pointer to the new (last) node in the list.
 */
Node* insertNode(Node* last, int data);

/*
 * printList function prints the data in the list to both the console and a file.
 * Inputs: Node* last - A pointer to the last node in the list.
 *         FILE* fp - A file pointer where the list data will be written.
 */
void printList(Node* last, FILE* fp);

/*
 * freeCircularList function frees the memory allocated to all the nodes in the list.
 * Input: Node* last - A pointer to the last node in the list.
 */
void freeCircularList(Node *last);
