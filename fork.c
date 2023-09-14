#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("pid:%d\n", getpid());
        int rc = fork();
        if(rc < 0){
                fprintf(stderr, "fork failed!\n");
                exit(1);
        }else if (rc == 0){ // child process 
                printf("I am child (pid:%d)\n", getpid());
        } else { // parent process
                printf("I am parent of %d (pid:%d)\n", rc, getpid());
        }

        return 0;
}
