/* stack.c -- the Stack type implementation*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* local functions */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeStack(Stack * pq){
    pq->rear = NULL;
    pq->items = 0;
}

bool StackIsFull(const Stack * pq){
    return pq->items == MAXSTACK;
}

bool StackIsEmpty(const Stack * pq){
    return pq->items == 0;
}

int StackItemCount(const Stack * pq){
    return pq->items;
}

bool EnStack(Item item, Stack * pq){
    Node * pnew;

    if (StackIsFull(pq))
        return false;

    pnew = (Node *) malloc( sizeof(Node));
    
    if (pnew == NULL){
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }

    CopyToNode(item, pnew);
    
    if (StackIsEmpty(pq)){
        pnew->prev = NULL;      /*only one node in stack so there is no prev node*/
    }
    else {
        pnew->prev = pq->rear;  /*new node points to rear node of stack*/
    }

    pq->rear = pnew;            /*new node becomes rear of stack*/
    pq->items++;                /* one more item in stack */

    return true;
}

bool DeStack(Item * pitem, Stack * pq){
    Node * pt;

    if (StackIsEmpty(pq))
        return false;
        
    CopyToItem(pq->rear, pitem); 

    pt = pq->rear;
    pq->rear = pq->rear->prev;
    free(pt);
    pq->items--;

    if (pq->items == 0)
        pq->rear = NULL;

    return true;
}

/* visit each node and execute function pointed to by pfun */
void TraverseStack (const Stack * pstack, void (* pfun)(Item item) ){
    Node * pnode = pstack->rear; /* set to rear of stack */

    while (pnode != NULL){
        (*pfun)(pnode->item); /* apply function to item */
        pnode = pnode->prev; /* advance to prev item */
    }
}

/* empty the stack */
void EmptyTheStack(Stack * pq){
    Item dummy;
    while (!StackIsEmpty(pq))
        DeStack(&dummy, pq);
}

/* Local functions */
static void CopyToNode(Item item, Node * pn){
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi){
    *pi = pn->item; 
} 