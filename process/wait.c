#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid, child_pid;
	int status;
	
	child_pid = fork();
	if(!child_pid)
		return 1;
//	pid = wait(&status);
	pid = waitpid(child_pid, &status, WNOHANG);
	if(pid == -1)
		perror("wait");
	printf("child_pid:%d, pid:%d\n", child_pid, pid);
	if(WIFEXITED(status))
		printf("normal termination with exit status=%d\n", WEXITSTATUS(status));
	if(WIFSTOPPED(status))
		printf("Stopped by signal=%d%s\n", WSTOPSIG(status),WCOREDUMP(status)?"(dump core)":"");
	if(WIFCONTINUED(status))
		printf("continued\n");
	return 0;
}
