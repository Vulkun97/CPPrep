/*Modify the Pet Club program so that all pets with the same name are stored in a list in 
the same node. When the user chooses to find a pet, the program should request the pet 
name and then list all pets (along with their kinds) having that name. 
*/

/* petclub.c -- use a binary search tree */
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include "tree.h"
 #include "list.h"

 char menu(void);
 void addpet(Tree * pt);
 void droppet(Tree * pt);
 void showpets(const Tree * pt);
 void findpet(const Tree * pt);
 void printitem(TreeItem item);
 void uppercase(char * str);
 char * s_gets(char * st, int n);
 void printkind(ListItem item);

 int main(void)
 {
 Tree pets;
 char choice;
 InitializeTree(&pets);
 while ((choice = menu()) != 'q')
 {
 switch (choice)
 {
 case 'a' : addpet(&pets);
 break;
 case 'l' : showpets(&pets);
 break;
 case 'f' : findpet(&pets);
 break;
 case 'n' : printf("%d pets in club\n",
 TreeItemCount(&pets));
 break;
 case 'd' : droppet(&pets);
 break;
 default : puts("Switching error");
 }
 }
 DeleteAllTree(&pets);
 puts("Bye.");
 return 0;
 }

 char menu(void)
 {
 int ch;
 puts("Nerfville Pet Club Membership Program");
 puts("Enter the letter corresponding to your choice:");
 puts("a) add a pet l) show list of pets");
 puts("n) number of pets f) find pets");
 puts("d) delete a pet q) quit");
 while ((ch = getchar()) != EOF)
 {
 while (getchar() != '\n') /* discard rest of line */
 continue;
 ch = tolower(ch);
 if (strchr("alrfndq",ch) == NULL)
 puts("Please enter an a, l, f, n, d, or q:");
 else
 break;
 }
 if (ch == EOF) /* make EOF cause program to quit */
 ch = 'q';
 return ch;
 }

void addpet(Tree * pt){
    char petname[SLEN];
    char petkind[SLEN];
    TreeItem *temp;

    if (TreeIsFull(pt))
        puts("No room in the club!");
    else{
        puts("Please enter name of pet:");
        s_gets(petname,SLEN);

        puts("Please enter pet kind:");
        s_gets(petkind,SLEN);

        uppercase(petname);
        uppercase(petkind);

        temp = MakeItem(petname, petkind);

        AddItemToTree(temp, pt);
    }


}

void showpets(const Tree * pt){
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
    TraverseTree(pt, printitem);
}

void printitem(TreeItem item){
    printf("Pet: %-19s Kind: ", item.petname);
    TraverseList(&(item.petkind), printkind);
    printf("\n");
}

void findpet(const Tree * pt){
    TreeItem *temp;

    char petname[SLEN];
    char petkind[SLEN];

    if (TreeIsEmpty(pt)){
        puts("No entries!");
        return; /* quit function if tree is empty */
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(petname, SLEN);

    puts("Please enter pet kind:");
    s_gets(petkind, SLEN);

    uppercase(petname);
    uppercase(petkind);

    temp = MakeItem(petname, petkind);

    printf("%s the %s ", petname, petkind);

    if (InTree(temp, pt))
        printf("is a member.\n");
    else
        printf("is not a member.\n");

    DeleteItem(temp);
}

void droppet(Tree * pt){
    TreeItem *temp;

    char petname[SLEN];
    char petkind[SLEN];

    if (TreeIsEmpty(pt)){
        puts("No entries!");
        return; /* quit function if tree is empty */
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(petname, SLEN);

    puts("Please enter pet kind:");
    s_gets(petkind, SLEN);

    uppercase(petname);
    uppercase(petkind);

    temp = MakeItem(petname, petkind);

    printf("%s the %s ", petname, petkind);

    if (DeleteItemFromTree(temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");

    DeleteItem(temp);
 }
 
void uppercase(char * str){
    while (*str){
        *str = toupper(*str);
    str++;
    }
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);

    if (ret_val){
        find = strchr(st, '\n'); // look for newline
    if (find) // if the address is not NULL,
        *find = '\0'; // place a null character there
    else
        while (getchar() != '\n')
            continue; // dispose of rest of line
    }

    return ret_val;
}

void printkind(ListItem item){
    printf("%s ", item.petkind); 
}