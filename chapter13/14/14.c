/*Digital images, particularly those radioed back from spacecraft, may have glitches. Add 
a de-glitching function to programming exercise 12. It should compare each value to its 
immediate neighbors to the left and right, above and below. If the value differs by more 
than 1 from each of its neighbors, replace the value with the average of the neighboring 
values. You should round the average to the nearest integer value. Note that the points 
along the boundaries have fewer than four neighbors, so they require special handling. 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 30

#define ROWS 20
#define CLMS 30

void denoise(int arr[ROWS][CLMS], int);

int main(int argc, char* argv[]){
    FILE* source_fp;
    FILE* dist_fp;

    char out_name[SIZE];
    int index = 0;

    int iarr[ROWS][CLMS];
    char sarr[ROWS][CLMS + 1];

    const char grathics[10] = {' ', '.', '\'', ':', '~', '*', '=', '&', '%', '#'};

    if (argc != 2){
        printf("Usage: program file");
        return 1;
    }

    if((source_fp = fopen(argv[1], "r")) == NULL){
        printf("Cant open %s", argv[1]);
        return 2;
    }

    while(isalnum(argv[1][index]) && index < (SIZE - 9)){
        out_name[index] = argv[1][index];
        index++;
    }

    strcat(out_name, "_out.txt");

    if((dist_fp = fopen(out_name, "w")) == NULL){
        printf("Cant create %s", out_name);
        return 3;
    }

    for(int i = 0; i < ROWS; i++){
        for (int k = 0; k < CLMS; k++){
            fscanf(source_fp, "%d", &iarr[i][k]);
        }
    }

    denoise(iarr, ROWS);

    for(int i = 0; i < ROWS; i++){
        for (int k = 0; k < CLMS; k++){
            fprintf(dist_fp, "%c", grathics[iarr[i][k]]);
            fprintf(stdout, "%c", grathics[iarr[i][k]]);
        }
        fprintf(dist_fp, "\n");
        fprintf(stdout, "\n");
    }

    printf("Done");
    return 0;
}

void denoise(int arr[][CLMS], int rows){
    int cell_count;
    int average;
    int noised;
    int difference;

    for (int i = 0; i < rows; i++){
        for (int k = 0; k < CLMS; k++){
            noised = 0;

            if(k > 0){
                difference = abs(arr[i][k] - arr[i][k-1]);
                difference > 1 ? noised = 1 : 1;
            }
            if(k < CLMS - 1){
                difference = abs(arr[i][k] - arr[i][k+1]);
                difference > 1 ? noised = 1 : 1;
            }
            if(i > 0){
                difference = abs(arr[i][k] - arr[i-1][k]);
                difference > 1 ? noised = 1 : 1;
            }
            if(i < rows - 1){
                difference = abs(arr[i][k] - arr[i+1][k]);
                difference > 1 ? noised = 1 : 1;
            }

            if (noised){
                cell_count = 0;
                average = 0;

                if(k > 0){
                    average += arr[i][k-1];
                    cell_count++;
                }
                if(k < CLMS - 1){
                    average += arr[i][k+1];
                    cell_count++;
                }
                if(i > 0){
                    average += arr[i-1][k];
                    cell_count++;
                }
                if(i < rows - 1){
                    average += arr[i+1][k];
                    cell_count++;
                }

                average = average / cell_count;
                arr[i][k] = average;
            }
        }
    }
}