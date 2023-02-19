#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret_from_fork, mypid;
    int test = 1;

    mypid = getpid();
    printf("Before: my pid is %d\n", mypid);

    ret_from_fork = fork();

    sleep(1);
    printf("After: my pid is %d, fork() said %d, test is %d\n",
            getpid(), ret_from_fork, test);    
}