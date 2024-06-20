 /* tree.c -- tree support functions */
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "tree.h"
 #include "list.h"


 /* local data type */
 typedef struct pair {
 TreeNode * parent;
 TreeNode * child;
 } Pair;


 /* protototypes for local functions */
 static TreeNode * MakeNode(const TreeItem * pi);
 static bool ToLeft(const TreeItem * i1, const TreeItem * i2);
 static bool ToRight(const TreeItem * i1, const TreeItem * i2);
 static void AddNodeToTree (TreeNode * new_node, TreeNode * root);
 static void InOrder(const TreeNode * root, void (* pfun)(TreeItem item));
 static Pair SeekTreeItem(const TreeItem * pi, const Tree * ptree);
 static void DeleteNodeFromTree(TreeNode **ptr);
 static void DeleteAllNodes(TreeNode * ptr);

 
 /* function definitions */
 void InitializeTree(Tree * ptree)
 {
 ptree->root = NULL;
 ptree->size = 0;
 }


 bool TreeIsEmpty(const Tree * ptree)
 {
 if (ptree->root == NULL)
 return true;
 else
 return false;
 }


 bool TreeIsFull(const Tree * ptree)
 {
 if (ptree->size == MAXITEMS*MAXITEMS)
 return true;
 else
 return false;
 }


 int TreeItemCount(const Tree * ptree)
 {
 return ptree->size;
 }


bool AddItemToTree(const TreeItem * pi, Tree * ptree){
    TreeNode * new_node;

    if (TreeIsFull(ptree)){
        fprintf(stderr,"Tree is full\n");
        return false; /* early return */
    }

    if ((new_node = SeekTreeItem(pi, ptree).child) != NULL){/*node is already in the tree - need only add petkind*/
        AddItemToList(pi->petkind.head->listitem, &(new_node->item.petkind));
        ptree->size++;
        return true;
    }

    new_node = MakeNode(pi); /* points to new node */

    if (new_node == NULL){
        fprintf(stderr, "Couldn't create node\n");
        return false; /* early return */
    }

    /* succeeded in creating a new node */
    ptree->size++;

    if (ptree->root == NULL) /* case 1: tree is empty */
        ptree->root = new_node; /* new node is tree root */
    else /* case 2: not empty */
        AddNodeToTree(new_node,ptree->root); /* add node to tree */
    return true; /* successful return */
 }


 bool InTree(const TreeItem * pi, const Tree * ptree)
 {
    Pair look;
    if ((look = SeekTreeItem(pi, ptree)).child == NULL)
        return false;

    return InList(pi->petkind.head->listitem, &(look.child->item.petkind));/////
}


bool DeleteItemFromTree(const TreeItem * pi, Tree * ptree){
    Pair look;

    if ((look = SeekTreeItem(pi, ptree)).child == NULL)
        return false;

    if(DeleteItemFromList(pi->petkind.head->listitem, &(look.child->item.petkind))){
        ptree->size--;
        if(look.child->item.petkind.count == 0) /* there was only one petkind in the list*/{
            if (look.parent == NULL) /* delete root item */
                DeleteNodeFromTree(&ptree->root);
            else if (look.parent->left == look.child)
                DeleteNodeFromTree(&look.parent->left);
            else
                DeleteNodeFromTree(&look.parent->right);
        }   
        return true;
    }
    else
        return false; /*no such petkind*/    
}


 void TraverseTree (const Tree * ptree, void (* pfun)(TreeItem item))
 {
 if (ptree != NULL)
 InOrder(ptree->root, pfun);
 }


 void DeleteAllTree(Tree * ptree)
 {
 if (ptree != NULL)
 DeleteAllNodes(ptree->root);
 ptree->root = NULL;
 ptree->size = 0;
 }


 /* local functions */
 static void InOrder(const TreeNode * root, void (* pfun)(TreeItem item))
 {
 if (root != NULL)
 {
 InOrder(root->left, pfun);
 (*pfun)(root->item);
 InOrder(root->right, pfun);
 }
 }


 static void DeleteAllNodes(TreeNode * root)
 {
 TreeNode * pright;
 if (root != NULL)
 {
 pright = root->right;
 DeleteAllNodes(root->left);
 EmptyTheList(&(root->item.petkind));
 free(root);
 DeleteAllNodes(pright);
 }
 }


 static void AddNodeToTree(TreeNode * new_node, TreeNode * root)
 {
 if (ToLeft(&new_node->item, &root->item))
 {
 if (root->left == NULL) /* empty subtree */
 root->left = new_node; /* so add node here */
 else
 AddNodeToTree(new_node, root->left);/* else process subtree*/
 }
 else if (ToRight(&new_node->item, &root->item))
 {
 if (root->right == NULL)
 root->right = new_node;
 else
 AddNodeToTree(new_node, root->right);
 }
 else /* should be no duplicates */
 {
 fprintf(stderr,"location error in AddNodeToTree()\n");
 exit(1);
 }
 }


 static bool ToLeft(const TreeItem * i1, const TreeItem * i2)
 {
 if (strcmp(i1->petname, i2->petname) < 0){
 return true;
 }
 
 else
 return false;
 }


 static bool ToRight(const TreeItem * i1, const TreeItem * i2)
 {
 if (strcmp(i1->petname, i2->petname) > 0)
 return true;
 else
 return false;
 }


 static TreeNode * MakeNode(const TreeItem * pi)
 {
 TreeNode * new_node;
 new_node = (TreeNode *) malloc(sizeof(TreeNode));
 if (new_node != NULL)
 {
 new_node->item = *pi;
 new_node->left = NULL;
 new_node->right = NULL;
 }
 return new_node;
 }


static Pair SeekTreeItem(const TreeItem * pi, const Tree * ptree){
    Pair look;

    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look; /* early return */

    while (look.child != NULL){
        if (ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        }
        else /* must be same if not to left or right */
            break; /* look.child is address of node with item */
    }

    return look; /* successful return */
}


 static void DeleteNodeFromTree(TreeNode **ptr)
 /* ptr is address of parent member pointing to target node */
 {
 TreeNode * temp;
 if ( (*ptr)->left == NULL)
 {
 temp = *ptr;
 *ptr = (*ptr)->right;
 EmptyTheList(&(temp->item.petkind));
 free(temp);
 }
 else if ( (*ptr)->right == NULL)
 {
 temp = *ptr;
 *ptr = (*ptr)->left;
 EmptyTheList(&(temp->item.petkind));
 free(temp);
 }
 else /* deleted node has two children */
 {
 /* find where to reattach right subtree */
 for (temp = (*ptr)->left; temp->right != NULL;
 temp = temp->right)
 continue;
 temp->right = (*ptr)->right;
 temp = *ptr;
 *ptr =(*ptr)->left;
 EmptyTheList(&(temp->item.petkind));
 free(temp);
 }
 } 

TreeItem * MakeItem(char petname[SLEN], char petkind[SLEN]){
    static TreeItem new_treeitem;
    ListItem new_listitem;

    strcpy(new_treeitem.petname, petname);
    InitializeList(&(new_treeitem.petkind));
    strcpy(new_listitem.petkind, petkind);
    AddItemToList(new_listitem, &(new_treeitem.petkind));

    return &new_treeitem;
}

void DeleteItem(TreeItem * pi){
    EmptyTheList((&pi->petkind));
}


