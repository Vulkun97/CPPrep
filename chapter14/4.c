/*Write a program that creates a structure template with two members according to the 
following criteria: 
 a. The first member is a social security number. The second member is a structure 
with three members. Its first member contains a first name, its second member 
contains a middle name, and its final member contains a last name. Create and 
initialize an array of five such structures. Have the program print the data in this 
format: 
 Dribble, Flossie M. –– 302039823 
Only the initial letter of the middle name is printed, and a period is added. Neither the 
initial (of course) nor the period should be printed if the middle name member is empty. 
Write a function to do the printing; pass the structure array to the function. 
 b. Modify part a. by passing the structure value instead of the address. */

#include <stdio.h>

#define MAX 40
#define SIZE 5

struct full_name{
    char first_name[MAX];
    char middle_name[MAX];
    char last_name[MAX];
};

struct person{
    unsigned int SSN;
    struct full_name fn;
};

struct person persons[SIZE] = {
    {302039823, {"Dribble", "Matue", "Flossie"}},
    {123456789, {"Arnold", "Albert", "Schwarcneger"}},
    {987654321, {"Ekaterina", "", "Gerasimova"}},
    {135792468, {"Daria", "Gnom", "Kurm"}},
    {246813579, {"Ksenia", "Ksu", "Victorovna"}}
};

void print_arr(struct person* persons, int size);

void print_st(struct person person1);

int main(void){
    print_arr(persons, SIZE);

    
    printf("\n");

    for (int i = 0; i < SIZE; i++){
        print_st(persons[i]);
    }
}

void print_arr(struct person* persons, int size){
    for (int i = 0; i < size; i++){
        if (persons[i].fn.middle_name[0] == '\0'){
            printf("%s, %s -- %u\n", persons[i].fn.first_name, persons[i].fn.last_name, persons[i].SSN);
        }
        else{
            printf("%s, %s %c. -- %u\n", persons[i].fn.first_name, persons[i].fn.last_name, persons[i].fn.middle_name[0], persons[i].SSN);
        }
    }
}

void print_st(struct person person1){
    if (person1.fn.middle_name[0] == '\0'){
            printf("%s, %s -- %u\n", person1.fn.first_name, person1.fn.last_name, person1.SSN);
        }
        else{
            printf("%s, %s %c. -- %u\n", person1.fn.first_name, person1.fn.last_name, person1.fn.middle_name[0], person1.SSN);
        }
}