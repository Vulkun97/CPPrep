 /* list.c -- functions supporting list operations */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "list.h"



/* local data type */
 typedef struct pair {
 ListNode * prev;
 ListNode * next;
 } Pair;

 /* local function prototype */
 static void CopyToListNode(ListItem item, ListNode * pnode);
 static Pair SeekListItem(const ListItem * pi, const List * plist);

 /* interface functions */
 /* set the list to empty */
 void InitializeList(List * plist)
 {
  plist->head = NULL;
  plist->end = NULL;
  plist->count = 0; 
 }


 /* returns true if list is empty */
 bool ListIsEmpty(const List * plist)
 {
 return (plist->count == 0);
 }


 /* returns true if list is full */
 bool ListIsFull(const List * plist)
 {
 ListNode * pt;
 bool full;
 pt = (ListNode *) malloc(sizeof(ListNode));
 if (pt == NULL)
 full = true;
 else
 full = false;
 free(pt);
 return full;
 }

 /* returns number of nodes */
 unsigned int ListItemCount(const List * plist)
 {
 return plist->count; 
 }


/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist*/
bool AddItemToList(ListItem item, List * plist){
    ListNode * pnew;
    ListNode * scan = plist->head;

    pnew = (ListNode *) malloc(sizeof(ListNode));

    if (pnew == NULL)
        return false; /* quit function on failure */

    CopyToListNode(item, pnew);

    pnew->next = NULL;

    if (scan == NULL){      /* empty list, so place */
        plist->head = pnew; /* pnew at head of list */
        plist->end = pnew;  /* pnew at end of list */} 
    else{
        plist->end->next = pnew;   /* add pnew to end */
        plist->end = pnew;         /*update end of list*/
    }

    plist->count++;
    return true;
}

/* deletes node with item */
bool DeleteItemFromList(ListItem item, List * plist){
    Pair look;
    ListNode * temp;

    look = SeekListItem(&item, plist);

    if (look.next == NULL)/*no such item*/
        return false;

    if (look.prev == NULL) /* delete root item */{
        if(look.next->next == NULL){ /*only one item in the list*/
            temp = plist->head;
            plist->head = NULL;
            plist->end = NULL;
            
        }
        else{
            temp = look.next;
            plist->head = look.next->next;
        }
    }
    else{
        temp = look.next;
        look.prev->next = look.next->next;
    }



    free(temp);
    plist->count--;
    return true;
}


 /* visit each node and execute function pointed to by pfun */
 void TraverseList (const List * plist, void (* pfun)(ListItem item) )
 {
 ListNode * pnode = plist->head; /* set to start of list */
 while (pnode != NULL)
 {
 (*pfun)(pnode->listitem); /* apply function to item */
 pnode = pnode->next; /* advance to next item */
 }
 }


 /* free memory allocated by malloc() */
 /* set list pointer to NULL */
 void EmptyTheList(List * plist)
 {
 ListNode * psave;
 while (plist->head != NULL)
 {
 psave = plist->head->next; /* save address of next node */
 free(plist->head); /* free current node */
 plist->head = psave; /* advance to next node */
 }

 plist->count = 0;
 }

 
 /* local function definition */
 /* copies an item into a node */
 static void CopyToListNode(ListItem item, ListNode * pnode)
 {
 pnode->listitem = item; /* structure copy */
 }

 static Pair SeekListItem(const ListItem * pi, const List * plist){
    Pair look;
    look.prev = NULL;
    look.next = plist->head;

    while(look.next != NULL){
        if(!strcmp(look.next->listitem.petkind, pi->petkind)){
            break;
        }

        look.prev = look.next;
        look.next = look.next->next;

    }

    return look;
 }


 bool InList(ListItem item, List * plist){
    return (SeekListItem(&item, plist).next != NULL);
 }