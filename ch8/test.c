#include <stdio.h>

int main()
{
    char *buf[2];
    char c[2];
    c[0] = 'a';
    c[1] = 'b';
    c[2] = '\0';
    buf[0] = c;
    printf("%s", c);
}