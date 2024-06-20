/* list.h -- header file for a simple list type */
#ifndef LIST_H_

 #define LIST_H_

 #include <stdbool.h> /* C99 feature */

 /* program-specific declarations */
 #define SLEN 30 /* size of array to hold title */


 typedef struct listitem{
    char petkind[SLEN];
 } ListItem;

 typedef struct listnode
 {
 ListItem listitem;
 struct listnode * next;
 } ListNode;

 typedef struct list
 {
 ListNode * head; /* points to head of list */
 ListNode * end; /* points to end of list */
 unsigned int count; /* node count */
 } List; 

 /* function prototypes */
 /* operation: initialize a list */
 /* preconditions: plist points to a list */
 /* postconditions: the list is initialized to empty */
 void InitializeList(List * plist);

 /* operation: determine if list is empty */
 /* plist points to an initialized list */
 /* postconditions: function returns True if list is empty */
 /* and returns False otherwise */
 bool ListIsEmpty(const List *plist);

 /* operation: determine if list is full */
 /* plist points to an initialized list */
 /* postconditions: function returns True if list is full */
 /* and returns False otherwise */
 bool ListIsFull(const List *plist);

 /* operation: determine number of items in list */
 /* plist points to an initialized list */
 /* postconditions: function returns number of items in list */
 unsigned int ListItemCount(const List *plist);

 /* operation: add listitem to end of list */
 /* preconditions: listitem is an listitem to be added to list */
 /* plist points to an initialized list */
 /* postconditions: if possible, function adds listitem to end */
 /* of list and returns True; otherwise the */
 /* function returns False */
 bool AddItemToList(ListItem listitem, List * plist);

 /* operation: apply a function to each listitem in list */
 /* plist points to an initialized list */
 /* pfun points to a function that takes an */
 /* ListItem argument and has no return value */
 /* postcondition: the function pointed to by pfun is */
 /* executed once for each listitem in the list */
 void TraverseList (const List *plist, void (* pfun)(ListItem listitem) );

 /* operation: free allocated memory, if any */
 /* plist points to an initialized list */
 /* postconditions: any memory allocated for the list is freed */
 /* and the list is set to empty */
 void EmptyTheList(List * plist);

 bool DeleteItemFromList(ListItem item, List * plist);

 bool InList(ListItem item, List * plist);

 #endif 
