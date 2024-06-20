/*  A text file holds information about a softball team. Each line has data arranged as 
follows: 

    4 Jessie Joybat 5 2 1 1

    The first item is the player’s number, conveniently in the range 0–18.
    The second item is the player’s first name (single word),
    and the third is the player’s last name (single word). 
    The next item is the player’s official times at bat, 
    followed by the number of hits, 
    walks, 
    and runs batted in (RBIs).

    The file may contain data for more than one game, so the same player may have 
more than one line of data, and there may be data for other players between those lines. 
Write a program that stores the data into an array of structures. The structure should have 
members to represent the first and last names, the at bats, hits, walks, and RBIs (runs batted in), 
and the batting average (to be calculated later). You can use the player number as an array index. 
The program should read to end of-file, and it should keep cumulative totals for each player.
    The simplest way for the program to proceed is to initialize the structure contents to 
zeros, read the file data into temporary variables, and then add them to the contents of 
the corresponding structure. After the program has finished reading the file, it should 
then calculate the batting average for each player and store it in the corresponding 
structure member. The batting average is calculated by dividing the cumulative number 
of hits for a player by the cumulative number of at-bats; it should be a floating-point 
calculation. The program should then display the cumulative data for each player along 
witha line showing the combined statistics for the entire team. */

#include <stdio.h>
#include <string.h>

#define NSIZE 30
#define PSIZE 18

struct player{
    char first_name[NSIZE];
    char last_name[NSIZE];
    unsigned int bats;
    unsigned int hits;
    unsigned int walks;
    unsigned int rbi;
    float butting_average;
};

void ini_players(struct player*, int size);

int parse_player(struct player*, FILE*);

void add_player(int, struct player, struct player*, int size);

void calc_average(struct player*, int size);

void display_stat(struct player*, int size);

int main(int argc, char* argv[]){
    struct player players[PSIZE];
    struct player new_player;
    int player_index;

    FILE* fp;

    if(argc != 2){
        printf("Usage: programm file_name");
        return -1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Cant open file %s", argv[1]);
        return -2;
    }

    ini_players(players, PSIZE);

    while((player_index = parse_player(&new_player, fp)) != -1){
        add_player(player_index, new_player, players, PSIZE);
    }

    calc_average(players, PSIZE);

    display_stat(players, PSIZE);


    printf("Done");
    return 0;
}

void ini_players(struct player* players, int size){
    for(int i = 0; i < size; i++){
        players[i].first_name[0] = '\0';
        players[i].last_name[0] = '\0';
        players[i].bats = 0;
        players[i].hits = 0;
        players[i].walks = 0;
        players[i].rbi = 0;
        players[i].butting_average = 0.0;
    }
}

int parse_player(struct player* new_player, FILE* fp){
    int index;

    if(fscanf(fp, "%d %30s %30s %d %d %d %d",
    &index, &new_player->first_name, &new_player->last_name, &new_player->bats,
    &new_player->hits, &new_player->walks, &new_player->rbi) != 7)
        return -1;

    return index;
}

void add_player(int player_index, struct player new_player, struct player* players, int size){
    if(player_index < size){
        strcpy(players[player_index].first_name, new_player.first_name);
        strcpy(players[player_index].last_name, new_player.last_name);

        players[player_index].bats += new_player.bats;
        players[player_index].hits += new_player.hits;
        players[player_index].walks += new_player.walks;
        players[player_index].rbi += new_player.rbi;
    }
}

void calc_average(struct player* players, int size){
    for(int i = 0; i < size; i++){
        if(players[i].first_name[0] == '\0')
            continue;
            
        players[i].butting_average = (float)players[i].hits/players[i].bats;
    }
}

void display_stat(struct player* players, int size){
    printf("Player    First          Last           Times     Number    Number    RBI       Butting   \n");
    printf("index     name           name           at bat    of hits   of walks            average   \n");
    
    for (int i = 0; i < size; i++){
        if(players[i].first_name[0] == '\0')
            continue;

        printf("%9d %14s %14s %9u %9u %9u %9u %9.2f\n",
        i, players[i].first_name, players[i].last_name, players[i].bats, players[i].hits, players[i].walks, players[i].rbi, players[i].butting_average);
    }
}
