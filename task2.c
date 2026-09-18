#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1 = fork();
	if (pid1 == -1) {
		perror("fork1");
	}
	
	if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
	}
	
	wait(NULL);
	
	pid_t pid2 = fork();
	
	if (pid1 == -1) {
		perror("fork2");
	}
	
	if (pid2 == 0) {
		execl("/bin/date", "date", NULL);
	}
	
	wait(NULL);

	printf("Parent process done.\n");
	
	return 0;
}
