#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
        printf("pid:%d\n", getpid());
        int rc = fork();
        if (rc < 0)
        {
                fprintf(stderr, "fork failed!\n");
                exit(1);
        }
        else if (rc == 0)
        { // child process
                printf("I am child (pid:%d)\n", getpid());
        }
        else
        {                            // parent process
                int wc = wait(NULL); // waits for child to return
                printf("I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
        }

        return 0;
}
