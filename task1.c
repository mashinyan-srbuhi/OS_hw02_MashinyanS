#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();

	if (pid == 0) {
		execl("/usr/bin/ls", "ls", NULL);
		perror("execl");
		exit(1);
	} else if (pid > 0) {
		wait(NULL);    
        	printf("Parent process done.\n");
	} else if (pid == -1){
		perror("fork");
		exit(1);
	}

	return 0;
}
