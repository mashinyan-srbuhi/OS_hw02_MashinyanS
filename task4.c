#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	
	pid = fork();
	
	if (pid == 0) {
		execl("/bin/grep", "grep", "main", "test.txt", NULL);
		perror("execl");
		exit(1);
	} else if (pid > 0) {
		wait(NULL);
		printf("Parent process completed.\n");
	} else if (pid == -1) {
		perror("fork");
		exit(1);
	}

	return 0;

}
