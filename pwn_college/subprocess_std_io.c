#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int pwncollege(void)
{
	pid_t pid;
	int status;
	if((pid=vfork()) < 0)
	{
		printf("vfork error!\n");
		exit(1);
	}
	else if(pid==0)
	{
		printf("Child process PID: %d.\n", getpid());
		char *argv[ ]={"/challenge/embryoio_level30"};  
		char *envp[ ]={"PATH=/bin", NULL};
		if(execve(argv[0], argv, envp) < 0)
		{
			printf("subprocess error");
			exit(1);
		}
		printf("You should never see this message.");
	}
	else
	{
		printf("Parent process PID: %d.\n", getpid());
		waitpid(pid, &status, 0);
	}
	return 0;
}

int main() {
	pwncollege();
}
