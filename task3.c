#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	
	if (pid == 0) {
		execl("/bin/echo", "echo", 
				"Hello from the child process.", NULL);
	} else if (pid > 0) {
		wait(NULL);
		printf("Parent process done.\n");
	} else if (pid == -1) { 
		perror("fork");
	}
	
	return 0;
}

