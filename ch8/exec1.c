#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arglist[3];

    arglist[0] = "ls";
    arglist[1] = "-l";
    arglist[2] = 0;
    printf("*** About to excels - l\n");
    // {   
    //     printf("%d", 1);
    //     execvp("ls", arglist);
    // }
    printf("*** ls is done. bye");
}