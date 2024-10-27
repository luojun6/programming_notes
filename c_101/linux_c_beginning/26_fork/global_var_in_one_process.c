#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
    int x = 1;

    if (fork() == 0)
        // x belongs to child process
        printf("Child has x = %d\n", ++x);
    else
        // x belongs to parent process
        printf("Parent has x = %d\n", --x);
}
int main()
{
    forkexample();
    return 0;
}