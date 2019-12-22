#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int pid = 0;
	int ret = 0;
	sscanf(argv[1], "%d", &pid);
	ret = kill(pid, SIGUSR1);
	return ret;
}
