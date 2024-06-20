#include <stdio.h>

int wordlen (const char str[]);

int read(char* str, int size);

int main (void)
{
   char str[11];

   read(str, 10);

   printf("%d", wordlen(str));

}

int wordlen (const char str[]){
    int index = 0;
    int length = 0;
    while(str[index++] == ' ')
        continue;
    
    while(str[index + length - 1] != ' ' && str[index + length - 1] != '\0')
        length++;
    

    return length;
}

int read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if (str[i] == '\n')
            goto read_end;
        if (str[i] == EOF)
            return EOF;
    }

    while(getchar() != '\n')
        continue;

    read_end:
        str[i] = '\0';
        return 1;
}
