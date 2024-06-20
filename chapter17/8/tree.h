/* tree.h -- binary search tree */
/* no duplicate items are allowed in this tree */

#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#include "list.h"
#define MAXITEMS 10




 /* redefine TreeItem as appropriate */
 typedef struct treeitem
 {
  char petname[SLEN];
  List petkind; /*point to list of kinds of pet*/
 
 } TreeItem;


 typedef struct treenode
 {
 TreeItem item;
 struct treenode * left; /* pointer to right branch */
 struct treenode * right; /* pointer to left branch */
 } TreeNode;


 typedef struct tree
 {
 TreeNode * root; /* pointer to root of tree */
 int size; /* number of items in tree */
 } Tree;


 /* function prototypes */
 /* operation: initialize a tree to empty */
 /* preconditions: ptree points to a tree */
 /* postconditions: the tree is initialized to empty */
 void InitializeTree(Tree * ptree);


 /* operation: determine if tree is empty */
 /* preconditions: ptree points to a tree */
 /* postconditions: function returns true if tree is */
 /* empty and returns false otherwise */
 bool TreeIsEmpty(const Tree * ptree);


 /* operation: determine if tree is full */
 /* preconditions: ptree points to a tree */
 /* postconditions: function returns true if tree is */
 /* full and returns false otherwise */
 bool TreeIsFull(const Tree * ptree);


 /* operation: determine number of items in tree */
 /* preconditions: ptree points to a tree */
 /* postconditions: function returns number of items in */
 /* tree */
 int TreeItemCount(const Tree * ptree);


 /* operation: add an item to a tree */
 /* preconditions: pi is address of item to be added */
 /* ptree points to an initialized tree */
 /* postconditions: if possible, function adds item to */
 /* tree and returns true; otherwise, */
 /* the function returns false */
 bool AddItemToTree(const TreeItem * pi, Tree * ptree);


 /* operation: find an item in a tree */
 /* preconditions: pi points to an item */
 /* ptree points to an initialized tree */
 /* postconditions: function returns true if item is in */
 /* tree and returns false otherwise */
 bool InTree(const TreeItem * pi, const Tree * ptree);


 /* operation: delete an item from a tree */
 /* preconditions: pi is address of item to be deleted */
 /* ptree points to an initialized tree */
 /* postconditions: if possible, function deletes item */
 /* from tree and returns true; */
 /* otherwise the function returns false*/
 bool DeleteItemFromTree(const TreeItem * pi, Tree * ptree);


 /* operation: apply a function to each item in */
 /* the tree */
 /* preconditions: ptree points to a tree */
 /* pfun points to a function that takes*/
 /* an TreeItem argument and has no return */
 /* value */
 /* postcondition: the function pointed to by pfun is */
 /* executed once for each item in tree */
 void TraverseTree (const Tree * ptree, void (* pfun)(TreeItem item));


 /* operation: delete everything from a tree */
 /* preconditions: ptree points to an initialized tree */
 /* postconditions: tree is empty */
 void DeleteAllTree(Tree * ptree);

 void DeleteItem(TreeItem * pi);

 TreeItem * MakeItem(char petname[SLEN], char petkind[SLEN]);

 #endif