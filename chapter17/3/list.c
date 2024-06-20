/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/* local function prototype */
static void CopyToNode(Item item, Node * pnode);


/* interface functions */
/* set the list to empty */
void InitializeList(List * plist){
    plist->items = 0;
}


/* returns true if list is empty */
bool ListIsEmpty(const List * plist){
    if (plist->items == 0)
        return true;
    else
        return false;
}


/* returns true if list is full */
bool ListIsFull(const List * plist){
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist){
    return plist->items;
}


/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItem(Item item, List * plist){

    if (ListIsFull(plist))
        return false; /* quit function on failure */

    plist->entries[plist->items] = item;

    (plist->items)++;

    return true;
}


/* visit each node and execute function pointed to by pfun */
void Traverse (const List * plist, void (* pfun)(Item item) ){
    unsigned int index = 0;
    while (index < plist->items){
        (*pfun)(plist->entries[index++]); /* apply function to item */
    }
}


 /* free memory allocated by malloc() */
 /* set list pointer to NULL */
void EmptyTheList(List * plist){
    ;
}

 
 /* local function definition */
 /* copies an item into a node */
 static void CopyToNode(Item item, Node * pnode)
 {
 pnode->item = item; /* structure copy */
 }