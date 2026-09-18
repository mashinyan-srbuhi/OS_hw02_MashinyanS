#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid1 = fork();
	if (pid1 == -1) {
		perror("fork1");
		exit(1);
	}
	
	if (pid1 == 0) {
        	execl("/usr/bin/ls", "ls", NULL);
		perror("execl1");
		exit(1);
	}
	
	wait(NULL);
	
	pid_t pid2 = fork();
	
	if (pid1 == -1) {
		perror("fork2");
		exit(1);
	}
	
	if (pid2 == 0) {
		execl("/usr/bin/date", "date", NULL);
		perror("execl2");
	}
	
	wait(NULL);

	printf("Parent process done.\n");
	
	return 0;
}
