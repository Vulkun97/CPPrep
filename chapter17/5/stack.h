/* stack.h -- interface for a stack */

#ifndef _STACK_H_

#define _STACK_H_
#include <stdbool.h>

#define MAXSTACK 10

typedef struct item{
    char character;
} Item;

typedef struct node{
    Item item;
    struct node * prev;
} Node;

typedef struct stack{
    Node * rear; /* pointer to rear node of stack*/
    int items; /* number of items in stack */
} Stack;

/* operation: initialize the stack */
/* precondition: pq points to a stack */
/* postcondition: stack is initialized to being empty */
void InitializeStack(Stack * pq);

/* operation: check if stack is full */
/* precondition: pq points to previously initialized stack */
/* postcondition: returns True if stack is full, else False */
bool StackIsFull(const Stack * pq);

/* operation: check if stack is empty */
/* precondition: pq points to previously initialized stack */
/* postcondition: returns True if stack is empty, else False */
bool StackIsEmpty(const Stack *pq);

/* operation: determine number of items in stack */
/* precondition: pq points to previously initialized stack */
/* postcondition: returns number of items in stack */
int StackItemCount(const Stack * pq);

/* operation: add item to rear of stack */
/* precondition: pq points to previously initialized stack */
/* item is to be placed at rear of stack */
/* postcondition: if stack is not empty, item is placed at */
/* rear of stack and function returns */
/* True; otherwise, stack is unchanged and */
/* function returns False */
bool EnStack(Item item, Stack * pq);

void TraverseStack (const Stack * pstack, void (* pfun)(Item item));

/* operation: remove item from rear of stack */
/* precondition: pq points to previously initialized stack */
/* postcondition: if stack is not empty, item at rear of */
/* stack is copied to *pitem and deleted from */
/* stack, and function returns True; if the */
/* operation empties the stack, the stack is */
/* reset to empty. If the stack is empty to */
/* begin with, stack is unchanged and the */
/* function returns False */
bool DeStack(Item *pitem, Stack * pq);

/* operation: empty the stack */
/* precondition: pq points to previously initialized stack */
/* postconditions: the stack is empty */
void EmptyTheStack(Stack * pq);

#endif