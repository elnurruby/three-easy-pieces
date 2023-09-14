#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
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
        close(STDOUT_FILENO);
        open ("./test.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        char *args[3];
        args[0] = strdup("echo");
        args[1] = strdup("Hello from exec function!");
        args[2] = NULL;
        execvp(args[0], args); // executes
    }
    else
    {                        // parent process
        int wc = wait(NULL); // wait for child
    }
    return 0;
}