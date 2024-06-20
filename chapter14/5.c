/*Write a program that fits the following recipe:

 a. Externally define a name structure template with two members: a string to hold the 
first name and a string to hold the second name.

 b. Externally define a student structure template with three members: a name
structure, a grade array to hold three floating-point scores, and a variable to hold 
the average of those three scores.

 c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student 
structures and initialize the name portions to names of your choice. Use functions 
to perform the tasks described in parts d., e., f., and g.

 d. Interactively acquire scores for each student by prompting the user with a student 
name and a request for scores. Place the scores in the grade array portion of the 
appropriate structure. The required looping can be done in main() or in the 
function, as you prefer.

 e. Calculate the average score value for each structure and assign it to the proper 
member. 

 f. Print the information in each structure. 

 g. Print the class average for each of the numeric structure members. 
*/

#include <stdio.h>

#define SIZE 40
#define CSIZE 4
#define GSIZE 3

struct name{
    char first_name[SIZE];
    char second_name[SIZE];
};

struct student{
    struct name name;
    float grades[GSIZE];
    float average;
};

void grade_request(struct student* students, int s_index, int g_index);

void average_grade(struct student* students, int size);

void print_class(struct student* students, int size);

void print_average(struct student* students, int size);

int main(void){
    struct student students[CSIZE] = {
        {{.first_name = "Daria", .second_name = "Durm"}},
        {{.first_name = "Katerina", .second_name = "Gerasimova"}},
        {{.first_name = "Evgeny", .second_name = "Khromov"}},
        {{.first_name = "Vasilisa", .second_name = "Burmagina"}},
    };


    for(int i = 0; i < CSIZE; i++){
        for(int k = 0; k < GSIZE; k++){
            grade_request(students, i, k);
        }
    }

    average_grade(students, CSIZE);

    print_class(students, CSIZE);

    print_average(students, CSIZE);
}

void grade_request(struct student* students, int s_index, int g_index){
    float grade;

    printf("Enter %d grade for %s %s:", g_index + 1, students[s_index].name.first_name, students[s_index].name.second_name);

    while(scanf("%f", &grade) != 1){
        while(getchar() != '\n')
            continue;
        printf("Enter %d grade for %s %s:", g_index + 1, students[s_index].name.first_name, students[s_index].name.second_name);
    }

    while(getchar() != '\n')
        continue;

    students[s_index].grades[g_index] = grade;
}

void average_grade(struct student* students, int size){
    float sum;

    for (int i = 0; i < size; i++){
        sum = 0;
        for(int k = 0; k < GSIZE; k++){
            sum += students[i].grades[k];
        }

        students[i].average = sum / GSIZE;
    }
}

void print_class(struct student* students, int size){
    for (int i = 0; i < size; i++){
        printf("%s %s, average score is %f\n", students[i].name.first_name, students[i].name.second_name, students[i].average);
    }
}

void print_average(struct student* students, int size){
    float sum = 0;

    for (int i = 0; i < size; i++){
        sum += students[i].average;
    }

    printf("Average score for the class is %f", sum / size);
}