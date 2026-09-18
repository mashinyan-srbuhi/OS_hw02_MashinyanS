#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() 
{
        printf("\nBefore fork: pid = %d, ppid = %d\n", getpid(), getppid());
		
	pid_t ret1 = fork();
	if (ret1 == -1) {
		perror("fork1\n");
	}
	printf("fork1: ret1 = %d, pid = %d, ppid = %d\n", ret1, getpid(), getppid());

        pid_t ret2 = fork();
	if (ret2 == -1) {
		perror("fork2\n");
        }
	printf("fork2: ret2 = %d, pid = %d, ppid = %d\n", ret2, getpid(), getppid());
 
        pid_t ret3 = fork();
	if (ret3 == -1) {
		perror("fork3\n");
        }
	printf("fork3: ret3 = %d, pid = %d, ppid = %d\n", ret3, getpid(), getppid());

	     
        return 0; 
}
