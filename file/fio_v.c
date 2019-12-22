#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <string.h>
int main()
{
	int fd;
	struct iovec iov[3];
	ssize_t nr;
	char *buf[] = {
		"this is first line\n",
		"this is second line\n",
		"this is third line\n"
	};
	fd = open("/home/fio_v", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	for(int i = 0; i < 3; i++)
	{
		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen(buf[i]) + 1;
	}
	nr = writev(fd, iov, 3);
	if(nr == -1)
	{
		perror("writev");
		return 1;
	}
	printf("writev %ld bytes\n", nr);
	if(close(fd))
	{
		perror("close");
		return 1;
	}
	return 0;
}

