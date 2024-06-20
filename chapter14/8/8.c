/*
The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes 
one flight daily. Write a seating reservation program with the following features: 

    a. The program uses an array of 12 structures. Each structure should hold a seat 
identification number, a marker that indicates whether the seat is assigned, the last 
name of the seat holder, and the first name of the seat holder. 

    b. The program displays the following menu: 
        To choose a function, enter its letter label:
            a) Show number of empty seats
            b) Show list of empty seats
            c) Show alphabetical list of seats
            d) Assign a customer to a seat assignment
            e) Delete a seat assignment
            f) Quit 

    c. The program successfully executes the promises of its menu. Choices d) and e) require additional input, and each should enable the user to abort an entry. 

    d. After executing a particular function, the program shows the menu again, except for choice f). 

    e. Data is saved in a file between runs. When the program is restarted, it first loads in the data, if any, from the file.
*/
#define SIZE 40
#define SEATS 12

#include <stdio.h>
#include <string.h>

struct seat {
    int number;
    char booked;
    char lname[SIZE];
    char fname[SIZE];
};

void empty_seats_number(struct seat*, int);
void empty_seats_list(struct seat*, int);
void show_seats(struct seat*, int);
void assign_customer(struct seat*, int);
void delete_customer(struct seat*, int);
char * s_gets(char * st, int n);

int main (void){
    struct seat plane[SEATS];
    FILE* fp;
    int index = 0;
    int size = sizeof(plane[0]);
    char answer;

    for(int i = 0; i < SEATS; i++){
        plane[i].number = i+1;
        plane[i].booked = 'n';
        plane[i].lname[0] = '\0';
        plane[i].fname[0] = '\0';
    }

    fp = fopen("plane.dat", "a+b");
    rewind(fp);

    while(index < SEATS && fread(&plane[index], size, 1, fp) == 1)
        index++;

    fclose(fp);

    fp = fopen("plane.dat", "wb");

    while(1){
        printf("To choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Quit\n");

        answer = getchar();
        while(getchar() != '\n')
            continue;

        switch (answer)
        {
        case 'a':
            empty_seats_number(plane, SEATS);
            break;

        case 'b':
            empty_seats_list(plane, SEATS);
            break;

        case 'c':
            show_seats(plane, SEATS);
            break;

        case 'd':
            assign_customer(plane, SEATS);
            break;

        case 'e':
            delete_customer(plane, SEATS);
            break;
    
        default:
            fwrite(&plane[0], size, SEATS, fp);
            fclose(fp);
            printf("Bye!");
            return 0;
        }
    }
}

void empty_seats_number(struct seat* plane, int size){
    int count = 0;
    printf("Not booked seats count:");
    for(int i = 0; i < size; i++){
        if (plane[i].booked != 'y')
            count++;
    }
    printf("%d\n", count);
}

void empty_seats_list(struct seat* plane, int size){
    int no_seats = 1;

    printf("Numbers of not booked seats:\n");
    for(int i = 0; i < size; i++){
        if (plane[i].booked != 'y') {
            printf("%d ", plane[i].number);
            no_seats = 0;
        };
    }
    if (no_seats){
        printf("all seats are booked.");
    }
    printf("\n");
}

void show_seats(struct seat* plane, int size){
    struct seat buffer[size];
    struct seat temp;

    for(int i = 0; i < size; i++){
        plane[i].number = i + 1;
        buffer[i] = plane[i];
    }

    for(int i = 0; i < size; i++){
        for(int k = i + 1; k < size; k++){
            if (strcmp(buffer[i].lname,buffer[k].lname) > 0){
                temp = buffer[i];
                buffer[i] = buffer[k];
                buffer[k] = temp;
            }
        }
    }

    printf("Alphabetical list of seats:\n");
    printf("Number   Booked   Last   First\n");
    printf("                  name   name\n");
    for(int i = 0; i < size; i++){
        printf("%5d         %c   %10s %10s\n", buffer[i].number, buffer[i].booked, buffer[i].lname, buffer[i].fname);
    }
}

void assign_customer(struct seat* plane, int size){
    int seat_number = 0;
    char name[SIZE];
    struct seat buffer;

    printf("Enter the seat number to book [a for abort an entry]: ");
    while (1){
        if (scanf("%d", &seat_number) != 1){
            if(getchar() == 'a'){
                while(getchar() != '\n')
                    continue;
                return;
            }
            else {
                printf("You must enter a number or an \'a\' for abort.\nTry again:");
                while(getchar() != '\n')
                    continue;
                continue;
            }      
        }

        if (seat_number > size+1 || seat_number < 1){
            printf("You must enter a number from 1 to %d or an \'a\' for abort.\nTry again:", size+1);
            while(getchar() != '\n')
                continue;
            continue;
        }

        if (plane[seat_number-1].booked == 'y'){
            printf("This seat is already booked.\nTry again:");
            while(getchar() != '\n')
                continue;
            continue;
        }
        else {
            buffer.number = seat_number;
            buffer.booked = 'y';
            break;
        }
    }

    while(getchar() != '\n')
        continue;

    printf("Now enter the last name [a for abort an entry]: \n");
    s_gets(name, SIZE);
    if (name[0] == 'a' && name[1] == '\0'){
        while(getchar() != '\n')
            continue;
        return;
    }
    strcpy(buffer.lname, name);

    printf("Now enter the first name [a for abort an entry]: \n");
    s_gets(name, SIZE);
    if (name[0] == 'a' && name[1] == '\0'){
        while(getchar() != '\n')
            continue;
        return;
    }
    strcpy(buffer.fname, name);

    plane[buffer.number-1] = buffer;

    printf("%d seat is booked for %s %s\n", buffer.number, buffer.lname, buffer.fname);
}

void delete_customer(struct seat* plane, int size){
    int seat_number;

    printf("Enter the seat to unbook [a for abort an entry]:");
    while (1){
        if (scanf("%d", &seat_number) != 1){
            if(getchar() == 'a'){
                while(getchar() != '\n')
                    continue;
                return;
            }
            else {
                printf("You must enter a number or an \'a\' for abort.\nTry again:");
                while(getchar() != '\n')
                    continue;
                continue;
            }      
        }

        if (seat_number > size+1 || seat_number < 1){
            printf("You must enter a number from 1 to %d or an \'a\' for abort.\nTry again:", size+1);
            while(getchar() != '\n')
                continue;
            continue;
        }

        if (plane[seat_number-1].booked != 'y'){
            printf("This seat is already empty.\nTry again:");
            while(getchar() != '\n')
                continue;
            continue;
        }
        else {
            while(getchar() != '\n')
                continue;
            plane[seat_number-1].booked = 'n';
            plane[seat_number-1].lname[0] = '\0';
            plane[seat_number-1].fname[0] = '\0';
            printf("%d seat is unbooked\n", seat_number);
            break;
        }
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