#include "list.h" /* Includes the Node structure and function prototypes for manipulating the circular linked list. */

/*
 * createNode function generates a new Node structure and assigns the data to it.
 * Input: An integer data which will be assigned to the node.
 * Output: A pointer to the new Node. If memory allocation fails, the program terminates.
 */
Node *createNode(int data)
{
    /* Pointer to the new node. */
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    /* Handle memory allocation failure. */
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    /* Assign data to the new node and make its next pointer point to itself. */
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

/*
 * insertNode function inserts a new node into the circular linked list.
 * If the list is empty, it creates a new list.
 * Input: A pointer to the last node in the list and the data for the new node.
 * Output: A pointer to the newly inserted node.
 */
Node *insertNode(Node *last, int data)
{
    /* Pointer to the new node. */
    Node *temp;
    /* If the list is empty, create a new list.*/
    if (last == NULL)
        return createNode(data);
    /* Create a new node and insert it after the last node in the list. */
    temp = createNode(data);
    temp->next = last->next;
    last->next = temp;
    return temp;
}

/*
 * printList function prints the data in the list to both the console and a file.
 * Input: A pointer to the last node in the list and a pointer to the file.
 */
void printList(Node *last, FILE *pF)
{
    /* Temporary pointer for traversing the list. */
    Node *temp;
    /* Handle the case where the list is empty. */
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    /*Print the data in the list. */
    temp = last->next;
    while (temp != last)
    {
        printf("%d ", temp->data);
        fprintf(pF, "%d ", temp->data);
        temp = temp->next;
    }
    /* Print the data in the last node. */
    printf("%d ", temp->data);
    fprintf(pF, "%d ", temp->data);
    printf("\n");
}

/*
 * freeCircularList function frees the memory allocated to all the nodes in the list.
 * Input: A pointer to the last node in the list.
 */
void freeCircularList(Node *last)
{
    /* Temporary pointers for traversing the list and keeping track of the next node. */
    Node *temp;
    Node *nextNode;
    if (last != NULL)
    {
        temp = last->next;
        /* Free all nodes except the last node. */
        while (temp != last)
        {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        /* Free the last node. */
        free(last);
    }
}
