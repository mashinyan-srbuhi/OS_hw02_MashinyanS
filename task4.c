#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	
	pid = fork();
	
	if (pid == 0) {
		execl("/bin/grep", "grep", "main", "test.txt", NULL);
	} else if (pid > 0) {
		wait(NULL);
		printf("Parent process completed.\n");
	} else {
		perror("fork");
	}

	return 0;

}
