/*Write a program that reads input as a stream of characters until encountering EOF. Have 
the program print each input character and its ASCII decimal value. Note that characters 
preceding the space character in the ASCII sequence are nonprinting characters. 
Treat them specially. If the nonprinting character is a newline or tab, print \n or \t , 
respectively. Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A, 
which can be displayed as ^A. Note that the ASCII value for A is the value for Ctrl+A 
plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per 
line, except start a fresh line each time a newline character is encountered. (Note: The 
operating system may have special interpretations for some control characters and keep 
them from reaching the program.)*/

#include <stdio.h>
#define MAX_SIZE 200

int main (void){
    int ch;
    int buffer[MAX_SIZE];
    int ch_count = 0;
    int ch_in_line = 1;

    printf("Enter your input: ");
    while ((ch = getchar()) != EOF && ch_count < 200){
        buffer[ch_count++] = ch;
    }

    

    for(int i = 0; i < ch_count; i++){
        if(buffer[i] >= ' '){
            printf("%2c %4i ", buffer[i], buffer[i]);
        }
        else {
        switch (buffer[i]){
            case 0:
                printf("\\0 %4i ", buffer[i]);
                break;
            case 7:
                printf("\\a %4i ", buffer[i]);
                break;
            case 8:
                printf("\\b %4i ", buffer[i]);
                break;
            case 9:
                printf("\\t %4i ", buffer[i]);
                break;
            case 10:
                printf("\\n %4i \n", buffer[i]);
                ch_in_line = 1;
                break;
            case 11:
                printf("\\v %4i ", buffer[i]);
                break;
            case 12:
                printf("\\f %4i ", buffer[i]);
                break;
            case 13:
                printf("\\r %4i ", buffer[i]);
                break;
            case 27:
                printf("\\e %4i ", buffer[i]);
                break;
            default:
                    printf("^%1c %4i ", buffer[i] + 64, buffer[i]);
                break;
            };
        };

        if (!(ch_in_line++ % 10))
            printf("\n");
    }

    printf("\nDone");
    return 0;
}