/*
 * This program generates Fibonacci series up to a user-specified number n
 * and stores it in a circular linked list. The list is then written to a file
 * and freed from memory.
 *
 * The model used here is a singly linked circular list with an integer data field.
 *
 * The Fibonacci series is generated using an iterative algorithm that starts from
 * the end of the series and works its way to the beginning.
 *
 * Input: A non-negative integer n provided by the user at runtime and the name of the output file provided as a command-line argument.
 * Output: A file containing the Fibonacci series up to n and the output of the list printed to the console.
 * 
 * Assumptions: 
 * - The user inputs a non-negative integer when prompted.
 * - The program has write access to the file system to create and write to the output file.
 */

#include "list.h" /* Provides the Node struct and functions for manipulating circular linked lists. */

/* Function to calculate the n-th Fibonacci number using an iterative algorithm. */
int fibonacci(int n);

int main(int argc, char *argv[])
{
    /* Filename for the output file. */
    char *filename;
    /* File pointer for the output file. */
    FILE *pF;
    /* Pointer to the last node in the circular list. */
    Node *last;
    /* Counter for the Fibonacci generation loop. */
    int i;
    /* The number up to which the Fibonacci series will be generated. */
    int n;

    /* Check that the correct number of command-line arguments was provided. */
    if (argc != 2)
    {
        printf("Incorrect number of arguments! Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    /* Open the output file for writing. */
    filename = argv[1];
    pF = fopen(filename, "w");
    if (pF == NULL)
    {
        printf("File %s could not be opened.\n", filename);
        return 1;
    }

    /* Print the introductory line to the file. */
    fprintf(pF, "This file contains a circular list of Fibonacci series.\n");
    
    /* Prompt the user for a non-negative integer. */
    printf("Please enter a non-negative integer: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Input must be a non-negative integer.\n");
        fclose(pF);
        return 1;
    }

    /* Print the chosen number to the file. */
    fprintf(pF, "The number chosen was %d.\n", n);
    
    /* Initialize the list as empty. */
    last = NULL;
    
    /* Generate the Fibonacci series in reverse order and insert each number into the list. */
    for (i = n; i >= 0; --i)
    {
        last = insertNode(last, fibonacci(i));
        if (last == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(pF);
            return 1;
        }
    }

    /* Print the list to the file and the console, then free the list from memory. */
    printList(last, pF);
    freeCircularList(last);
    
    /* Close the output file. */
    fclose(pF);

    return 0;
}

/*
 * The fibonacci function calculates the n-th Fibonacci number using an iterative algorithm.
 * Inputs: n - the index of the Fibonacci number to generate
 * Outputs: the n-th Fibonacci number
 */
int fibonacci(int n) {
    /* Variables to hold the two previous Fibonacci numbers and the current one in the series. */
    int prev2, prev1, result;
    /* Counter for the Fibonacci generation loop. */
    int i;

    /* Handle the base case where n <= 1. */
    if(n <= 1)
        return n;
    
    /* Initialize the two previous numbers to the first two numbers in the Fibonacci series. */
    prev2 = 0;  /* fib(0) */
    prev1 = 1;  /* fib(1) */
    result = 0;

    /* Generate the n-th Fibonacci number. */
    for(i = 2; i <= n; ++i) {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }
    
    return result;
}
