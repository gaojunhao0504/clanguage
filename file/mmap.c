#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	int fd;
	struct stat sb;
	char *p;

	fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
		return 1;
	}
	if(!S_ISREG(sb.st_mode))
	{
		fprintf(stderr, "%s is not a file\n", argv[1]);
		return 1;
	}
	p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		perror("mmap");
		return 1;
	}
	if(close(fd))
	{
		perror("close");
		return 1;
	}
	for(int len = 0; len < sb.st_size; len++)
	{
		putchar(p[len]);
	}
	if(munmap(p, sb.st_size) == -1)
	{
		perror("munmap");
		return 1;
	}
	return 0;
}
