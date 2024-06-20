/*Write a program with the same behavior as described in exercise 6, but use an unsigned 
long variable to hold the font information and use the bitwise operators instead of bit 
members to manage the information.*/

#include <stdio.h>
#include <limits.h>

#define ID_MASK 0x000000FF
#define SIZE_MASK 0x00007F00
#define ALIGNMENT_MASK 0x00018000
#define BOLD_MASK 0x00020000
#define ITALIC_MASK 0x00040000
#define UNDERLINE_MASK 0x00080000

struct  bf_font{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

void print_font(unsigned int *font);

void change_id(unsigned int *font);

void change_size(unsigned int *font);

void change_alignment(unsigned int *font);

void toggle_bold(unsigned int *font);

void toggle_italic(unsigned int *font);

void toggle_underline(unsigned int *font);

void skip(void);

int main(void){
    unsigned int font;
    char answer;
    
    while(1){
        print_font(&font);

        printf("f)change id s)change size a)change alignment\n");
        printf("b)toggle bold i)toggle italic u)toggle underline\n");
        printf("q)quit\n");
        
        
        scanf("%c", &answer);
        skip();

        switch(answer){
            case 'f':
                change_id(&font);
                skip();
                continue;
            case 's':
                change_size(&font);
                skip();
                continue;
            case 'a':
                change_alignment(&font);
                skip();
                continue;
            case 'b':
                toggle_bold(&font);
                skip();
                continue;
            case 'i':
                toggle_italic(&font);
                skip();
                continue;
            case 'u':
                toggle_underline(&font);
                skip();
                continue;
            case 'q':
                printf("Bye!");
                return 0;
            default:
                printf("Incorrect input. Please try again.\n");
                continue;
        }
    }
}

void print_font(unsigned int *font){
    printf("\n ID SIZE ALIGNMENT B I U\n");
    printf("%3u %4u         %c %c %c %c\n", *font & ID_MASK, (*font & SIZE_MASK) >> 8, (*font & ALIGNMENT_MASK ? (*font & ALIGNMENT_MASK > (ALIGNMENT_MASK >> 1) & ALIGNMENT_MASK ? 'R' : 'C') : 'L'), 
    (*font & BOLD_MASK ? 'Y' : 'N'), (*font & ITALIC_MASK ? 'Y' : 'N'), (*font & UNDERLINE_MASK ? 'Y' : 'N'));
};

void change_id(unsigned int *font){
    unsigned int new_id;

    *font &= ~ID_MASK;

    printf("Enter new id: ");
    while(!scanf("%d", &new_id)){
        skip();
        printf("Please try again: ");
    }

    *font |= (new_id & ID_MASK);
}

void change_size(unsigned int *font){
    unsigned int new_size;

    *font &= ~SIZE_MASK;

    printf("Enter new size: ");
    while(!scanf("%d", &new_size)){
        skip();
        printf("Please try again: ");
    }

    *font |= ((new_size << 8) & SIZE_MASK);
}


void change_alignment(unsigned int *font){
    unsigned int alignment;

    *font &= ~ALIGNMENT_MASK;

    printf("Enter new alignment('r' for right, 'c' for center, 'l' for left): ");
    scanf("%c", &alignment);

    while(1){
        switch (alignment){
            case 'r':
                *font |= ((ALIGNMENT_MASK << 1) & ALIGNMENT_MASK);
                return;
            case 'c':
                *font |= ((ALIGNMENT_MASK >> 1)  & ALIGNMENT_MASK);
                return;
            case 'l':
                return;
            default:
                skip();
                printf("Please try again: ");
                scanf("%c", &alignment);
                continue;
        }
    }
    
}

void toggle_bold(unsigned int *font){
    (*font & BOLD_MASK) ? (*font &= ~BOLD_MASK) : (*font |= BOLD_MASK);
}

void toggle_italic(unsigned int *font){
    (*font & ITALIC_MASK) ? (*font &= ~ITALIC_MASK) : (*font |= ITALIC_MASK);
}

void toggle_underline(unsigned int *font){
    (*font & UNDERLINE_MASK) ? (*font &= ~UNDERLINE_MASK) : (*font |= UNDERLINE_MASK);
}

void skip(void){
    while (getchar() != '\n')
        continue;
}