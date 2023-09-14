#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argvp[])
{
    printf("pid: %d\n", getpid());
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed!\n");
    }
    else if (rc == 0)
    { // child process
        printf("Hello I am child (pid:%d)", getpid());
        char *args[3];
        args[0] = strdup("echo");
        args[1] = strdup("Hello from exec function!");
        args[2] = NULL;
        execvp(args[0], args); // executes
        printf("*this should not print out*");
    }
    else
    {                        // parent process
        int wc = wait(NULL); // wait for child
        printf("I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
    }
    return 0;
}