#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int p;
	char *filename = "/usr/bin/vim";
	char *argv[] = {"vim","/home/fio_v",NULL};
	char *envp[] = {"/etc/profile"};

	pid_t pid, ppid, child_pid;
	pid = getpid();
	ppid = getppid();
	printf("pid:%d, ppid:%d\n", pid, ppid);

	child_pid = fork();
	if(child_pid == -1)
		perror("fork");
	if(!child_pid)
	{
		p = execve(filename, argv, envp);
		if(p == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
//	return 0;
	exit(EXIT_SUCCESS);
}
