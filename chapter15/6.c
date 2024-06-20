/*Design a bit-field structure that holds the following information: 
Font ID: A number in the range 0–255 
Font Size: A number in the range 0–127 
Alignment: A number in the range 0–2 represented the choices Left, Center, and Right 
Bold: Off (0) or on (1) 
Italic: Off (0) or on (1) 
Underline: Off (0) or on (1) 
 Use this structure in a program that displays the font parameters and uses a looped menu 
to let the user change parameters.
The program should use the & operator and suitable masks to ensure that the ID and size 
entries are converted to the specified range.*/

#include <stdio.h>
#include <limits.h>

struct  bf_font{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

void print_font(const struct bf_font * font);

void change_id(struct bf_font * font);

void change_size(struct bf_font * font);

void change_alignment(struct bf_font * font);

void toggle_bold(struct bf_font * font);

void toggle_italic(struct bf_font * font);

void toggle_underline(struct bf_font * font);

void skip(void);

int main(void){
    struct bf_font font;
    font.id = 12;
    font.size = 94;
    font.alignment = 1;
    font.bold = 0;
    font.italic = 1;
    font.underline = 0;

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
                continue;
            case 's':
                change_size(&font);
                continue;
            case 'a':
                change_alignment(&font);
                continue;
            case 'b':
                toggle_bold(&font);
                continue;
            case 'i':
                toggle_italic(&font);
                continue;
            case 'u':
                toggle_underline(&font);
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

void print_font(const struct bf_font * font){
    printf("\n ID SIZE ALIGNMENT B I U\n");
    printf("%3u %4u         %c %c %c %c\n", font->id, font->size, (font->alignment ? (font->alignment > 1 ? 'R' : 'C') : 'L'), 
    (font->bold ? 'Y' : 'N'), (font->italic ? 'Y' : 'N'), (font->underline ? 'Y' : 'N'));
};

void change_id(struct bf_font * font){
    unsigned int new_id;

    printf("Enter new id: ");
    while(!scanf("%d", &new_id)){
        skip();
        printf("Please try again: ");
    }

    font->id = new_id;
}

void change_size(struct bf_font * font){
    unsigned int new_size;

    printf("Enter new size: ");
    while(!scanf("%d", &new_size)){
        skip();
        printf("Please try again: ");
    }

    font->size = new_size;
}


void change_alignment(struct bf_font * font){
    unsigned int alignment;

    printf("Enter new alignment('r' for right, 'c' for center, 'l' for left): ");
    scanf("%c", &alignment);
    while(1){
        switch (alignment){
            case 'r':
                font->alignment = 2;
                return;
            case 'c':
                font->alignment = 1;
                return;
            case 'l':
                font->alignment = 0;
                return;
            default:
                skip();
                printf("Please try again: ");
                scanf("%c", &alignment);
                continue;
        }
    }
    
}

void toggle_bold(struct bf_font * font){
    font->bold = !font->bold;
}

void toggle_italic(struct bf_font * font){
    font->italic = !font->italic;
}

void toggle_underline(struct bf_font * font){
    font->underline = !font->underline;
}

void skip(void){
    while (getchar() != '\n')
        continue;
}