#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction?"

int get_response( char * );

int main()
{
    int response;
    tty_mode(0);
    set_crmode();
    response = get_response(QUESTION);
    tty_mode(1);
    return response;
}

int get_response(char *question)
{   
    int input;
    printf("%s (y/n)", question);
    while(1){
        switch( input = getchar() ){
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
            default:
                printf("\ncannot understand %c, ", input);
                printf("Please type y or n \ n");
        }
    }
}

