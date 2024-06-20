/*Modify the program in Listing 13.5so that it uses a command-line interface instead of an 
interactive interface. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);

char * s_gets(char * st, int n);

int main(int argc, char* argv[]){
    FILE *fa, *fs; // fa for append file, fs for source file
    int files = 0; // number of files appended
    int ch;

    if(argc != 3){
        printf("Usage: program dist_file src_file");
        return 1;
    }

    if ((fa = fopen(argv[1], "a+")) == NULL){
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[2], argv[1]) == 0)
        fputs("Can't append file to itself\n",stderr);
    else if ((fs = fopen(argv[2], "r")) == NULL)
        fprintf(stderr, "Can't open %s\n", argv[2]);
    else{
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
            fputs("Can't create input buffer\n",stderr);
                exit(EXIT_FAILURE);
        }
        append(fs, fa);
        if (ferror(fs) != 0)
            fprintf(stderr,"Error in reading file %s.\n", argv[2]);
        if (ferror(fa) != 0)
            fprintf(stderr,"Error in writing file %s.\n", argv[1]);
        fclose(fs);
        files++;
        printf("File %s appended.\n", argv[2]);
    }
    

    printf("Done appending. %d files appended.\n", files);
    fclose(fa);
    return 0;
}


void append(FILE *source, FILE *dest){
    size_t bytes;

    static char temp[BUFSIZE]; // allocate once

    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
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
    continue;

    }

    return ret_val;
}