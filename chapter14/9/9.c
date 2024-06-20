/*Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands 
its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to 
handle four flights. Have a top-level menu that offers a choice of flights and the option 
to quit. Selecting a particular flight should then bring up a menu similar to that of 
exercise 8. However, one new item should be added: confirming a seat assignment. Also, 
the quit choice should be replaced with the choice of exiting to the top-level menu. Each 
display should indicate which flight is currently being handled. Also, the seat assignment 
display should indicate the confirmation status. */
/*Добавить:
1. Разные полеты
2. Основное меню
3. Показывать полет в саб меню
4. Тэг подтверждения в структуре
5. Функция для подтверждения
6. Функция показывания мест должна показывать и подтверждение*/
#define SIZE 40
#define SEATS 12
#define FLIGHTS 4

#include <stdio.h>
#include <string.h>

struct seat {
    int flight;
    int number;
    char booked;
    char confirmed;
    char lname[SIZE];
    char fname[SIZE];
};

void empty_seats_number(struct seat*, int, int);
void empty_seats_list(struct seat*, int, int);
void show_seats(struct seat*, int, int);
void assign_customer(struct seat*, int, int);
void delete_customer(struct seat*, int, int);
void confirm_seat(struct seat*, int, int);
char * s_gets(char * st, int n);
void skip(void);

int main (void){
    struct seat plane[SEATS * FLIGHTS];
    FILE* fp;
    int index = 0;
    int size = sizeof(plane[0]);
    char answer;
    int flight = 0;

    for(int i = 0; i < SEATS * FLIGHTS; i++){
        plane[i].flight = i / SEATS + 1;
        plane[i].number = i % SEATS + 1;
        plane[i].booked = 'n';
        plane[i].confirmed = 'n';
        plane[i].lname[0] = '\0';
        plane[i].fname[0] = '\0';
    }

    fp = fopen("plane.dat", "a+b");
    rewind(fp);

    while(index < SEATS * FLIGHTS && fread(&plane[index], size, 1, fp) == 1)
        index++;

    fclose(fp);

    fp = fopen("plane.dat", "wb");

    while(1){
        main_menu:
        printf("Please enter the flight number from 1 to %d [any other input to quit]: ", FLIGHTS);
        if (scanf("%d", &flight) != 1){
            printf("Bye!");
            return 0;
        }
        if (flight < 1 || flight > 4){
            printf("Bye!");
            return 0;
        }

        while(1){
            skip();
            printf("\nEditing flight number %d.\n", flight);
            printf("To choose a function, enter its letter label:\n");
            printf("a) Show number of empty seats\n");
            printf("b) Show list of empty seats\n");
            printf("c) Show alphabetical list of seats\n");
            printf("d) Assign a customer to a seat\n");
            printf("e) Delete a seat assignment\n");
            printf("f) Confirm booked seats\n");
            printf("g) Go to the main menu\n");

            answer = getchar();
            
            switch (answer){
                case 'a':
                    empty_seats_number(plane, SEATS * FLIGHTS, flight);
                    continue;

                case 'b':
                    empty_seats_list(plane, SEATS * FLIGHTS, flight);
                    continue;

                case 'c':
                    show_seats(plane, SEATS * FLIGHTS, flight);
                    continue;

                case 'd':
                    assign_customer(plane, SEATS * FLIGHTS, flight);
                    continue;

                case 'e':
                    delete_customer(plane, SEATS * FLIGHTS, flight);
                    continue;

                case 'f':
                    confirm_seat(plane, SEATS * FLIGHTS, flight);
                    continue;
    
                default:
                    fwrite(&plane, size, SEATS * FLIGHTS, fp);
                    fclose(fp);
                    skip();
                    goto main_menu;
            }
        }
    }
}

void empty_seats_number(struct seat* plane, int size, int flight){
    int count = 0;
    printf("Not booked seats count:");
    for(int i = 0; i < size; i++){
        if (plane[i].booked != 'y' && plane[i].flight == flight)
            count++;
    }
    printf("%d\n", count);
}

void empty_seats_list(struct seat* plane, int size, int flight){
    int no_seats = 1;

    printf("Numbers of not booked seats:\n");
    for(int i = 0; i < size; i++){
        if (plane[i].booked != 'y' && plane[i].flight == flight) {
            printf("%d ", plane[i].number);
            no_seats = 0;
        };
    }
    if (no_seats){
        printf("all seats are booked.");
    }
    printf("\n");
}

void show_seats(struct seat* plane, int size, int flight){
    struct seat buffer[size];
    struct seat temp;

    for(int i = 0; i < size; i++){
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
    printf("Number   Booked   Confirmed   Last        First\n");
    printf("                              name        name\n");
    for(int i = 0; i < size; i++){
        if (buffer[i].flight == flight)
            printf("%5d         %c           %c   %10s %10s\n", buffer[i].number, buffer[i].booked, buffer[i].confirmed, buffer[i].lname, buffer[i].fname);
    }
}

void assign_customer(struct seat* plane, int size, int flight){
    int seat_number = 0;
    char name[SIZE];
    struct seat buffer;

    printf("Enter the seat number to book [a for abort an entry]: ");
    while (1){
        if (scanf("%d", &seat_number) != 1){
            if(getchar() == 'a'){
                return;
            }
            else {
                printf("You must enter a number or an \'a\' for abort.\nTry again:");
                continue;
            }      
        }

        if (seat_number > size+1 || seat_number < 1){
            printf("You must enter a number from 1 to %d or an \'a\' for abort.\nTry again:", size+1);
            continue;
        }

        if (plane[(seat_number-1) + ((flight-1) * SEATS)].booked == 'y'){
            printf("This seat is already booked.\nTry again:");
            continue;
        }
        else {
            buffer.number = seat_number;
            buffer.booked = 'y';
            buffer.confirmed = 'n';
            buffer.flight = flight;
            break;
        }
    }

    skip();

    printf("Now enter the last name [a for abort an entry]: \n");
    s_gets(name, SIZE);
    if (name[0] == 'a' && name[1] == '\0'){
        return;
    }
    strcpy(buffer.lname, name);

    printf("Now enter the first name [a for abort an entry]: \n");
    s_gets(name, SIZE);
    if (name[0] == 'a' && name[1] == '\0'){
        return;
    }
    strcpy(buffer.fname, name);

    plane[(buffer.number-1) + ((flight-1) * SEATS)] = buffer;

    printf("%d seat is booked for %s %s\n", buffer.number, buffer.lname, buffer.fname);
    printf("Press [Enter] to aknowledge\n");
}

void delete_customer(struct seat* plane, int size, int flight){
    int seat_number;

    printf("Enter the seat to unbook [a for abort an entry]:");
    while (1){
        if (scanf("%d", &seat_number) != 1){
            if(getchar() == 'a'){
                return;
            }
            else {
                printf("You must enter a number or an \'a\' for abort.\nTry again:");
                continue;
            }      
        }

        if (seat_number > size+1 || seat_number < 1){
            printf("You must enter a number from 1 to %d or an \'a\' for abort.\nTry again:", size+1);
            continue;
        }

        if (plane[(seat_number-1) + ((flight-1) * SEATS)].booked != 'y'){
            printf("This seat is already empty.\nTry again:");
            continue;
        }
        else {
            plane[(seat_number-1) + ((flight-1) * SEATS)].booked = 'n';
            plane[(seat_number-1) + ((flight-1) * SEATS)].confirmed = 'n';
            plane[(seat_number-1) + ((flight-1) * SEATS)].lname[0] = '\0';
            plane[(seat_number-1) + ((flight-1) * SEATS)].fname[0] = '\0';
            printf("%d seat is unbooked\n", seat_number);
            break;
        }
    }
}

void confirm_seat(struct seat* plane, int size, int flight){
    int seat_number;

    printf("Seats to confirm on flight %d:\n", flight);
    printf("Number   Booked   Confirmed   Last        First\n");
    printf("                              name        name\n");
    for(int i = 0; i < size; i++){
        if(plane[i].flight == flight && plane[i].booked == 'y' && plane[i].confirmed != 'y')
            printf("%5d         %c           %c   %10s %10s\n", plane[i].number, plane[i].booked, plane[i].confirmed, plane[i].lname, plane[i].fname);
    }

    printf("Enter the seat number to confirm [a for abort]:");
    while(1){
        if (scanf("%d", &seat_number) != 1){
            if(getchar() == 'a')
                return;
            printf("Enter the number or an \'a\' for abort. Try again:");
            continue;
        }

        if (seat_number < 1 || seat_number > SEATS){
            printf("Incorrect seat number. Try again [a for abort]:");
            continue;
        }

        if (plane[(seat_number-1) + ((flight-1) * SEATS)].booked != 'y'){
            printf("Seat %d is not booked. Try again [a for abort]:", seat_number);
            continue;
        }

        if (plane[(seat_number-1) + ((flight-1) * SEATS)].confirmed == 'y'){
            printf("Seat %d is already confirmed. Try again [a for abort]:", seat_number);
            continue;
        }

        plane[(seat_number-1) + ((flight-1) * SEATS)].confirmed = 'y';
        printf("Seat %d confirmed!\n", seat_number);
        return;
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
            skip();
    }

    return ret_val;
}

void skip(void){
    while(getchar() != '\n')
        continue;
}