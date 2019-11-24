#include <stdio.h>
#include <signal.h>
void signal_handler(int signo)
{
	printf("receive signal\n");
}

int main()
{
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		printf("register signal error\n");
	printf("waiting for signal\n");
	sleep(100000);
	return 0;
}
