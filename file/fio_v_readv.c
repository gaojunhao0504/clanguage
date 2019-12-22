#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
int main()
{
	int fd;
	ssize_t nr;
	struct iovec iov[3];
/*
	"this is first line" is 20 bytes	
*/
	char buf_1[20], buf_2[21], buf_3[20];
	fd = open("/home/fio_v", O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
/*
	sizeof: 获取数组的容量
	strlen: 获取字符串的长度
*/
	iov[0].iov_base = buf_1;
	iov[0].iov_len = sizeof(buf_1);
	iov[1].iov_base = buf_2;
	iov[1].iov_len = sizeof(buf_2);
	iov[2].iov_base = buf_3;
	iov[2].iov_len = sizeof(buf_3);
	nr = readv(fd, iov, 3);
	if(nr == -1)
	{
		perror("readv");
		return 1;
	}
	for(int i =0; i < 3; i++)
	{
		printf("%d item: %s", i, (char *) iov[i].iov_base);
	}
	if(close(fd))
	{
		perror("close");
		return 1;
	}
	return 0;
}

