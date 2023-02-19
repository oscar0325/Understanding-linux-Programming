#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARGS 20
#define ARGLEN 100

int main()
{   
    int execute(char *[]);

    char *arglist[MAXARGS+1];
    int numargs;
    char argbuf[ARGLEN]; //暂存命令参数
    char *makestring();
    numargs = 0;
    while ( numargs < MAXARGS)
    {
        printf("Arg[%d]", numargs);
        if( fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n')
            arglist[numargs++] = makestring(argbuf);
        else
        {
            if( numargs > 0){
                arglist[numargs] = NULL;
                execute(arglist);
                numargs = 0;
            }
        }
    }
    return 0;
}

int execute(char *arglist[])
{
    int pid, exitstatus;

    pid = fork(); //生成子进程
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    
    case 0:
        execvp(arglist[0], arglist);
        perror("execvp failed");
        exit(1);

    default:
        while (wait(&exitstatus) != pid) //wait出错，进程不一定出错，反复调用wait，获取进程退出信息
            ;
        printf("child exited with status %d, %d\n", exitstatus >> 8, exitstatus & 0377);
    }

}

char *makestring(char *buf)
{
    char *cp;
    buf[strlen(buf) - 1] = '\0'; //fgets读入了'\n',用'0'替代
    cp = (char *) malloc(strlen(buf) + 1);
    if( cp == NULL){
        fprintf(stderr, "no memory\n");
        exit(1);
    }
    strcpy(cp, buf);
    return cp;
}
