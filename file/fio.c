#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd, ffd;
	FILE *stream, *stream_read;

	fd = open("/home/tmp", O_RDWR, __O_DIRECT);
	if(fd != -1)
	{
		stream = fdopen(fd, "w+");
		if(stream)
			printf("fdopen successfully\n");
		else
			printf("fdopen error\n");

		int t;
		t = fputc('p', stream);
		if(t == EOF)
			printf("fputc error\n");
		else
			printf("fputc successfully, t: %c\n", t);

		t = fputs("fputs one line", stream);
		if(t == EOF)
			printf("fputs error\n");
		else
			printf("fputs successfully\n");

		fclose(stream);
	}
	else
	{
		printf("open file error\n");
		close(fd);
	}

	ffd = open("/home/tmp", O_RDWR, __O_DIRECT);
	if(ffd != -1)
	{
		stream_read = fdopen(ffd, "r+");
		if(stream_read)
			printf("fdopen successfully\n");
		else
			printf("fdopen error\n");

		int c;
		c = fgetc(stream_read);
		if(c == EOF)
			printf("fgetc error\n");
		else
			printf("fgetc char: %c\n", (char) c);

		char str[20];
		if(fgets(str, 20, stream_read))
			printf("fgets successfully, str: %s\n", str);
		else
			printf("fgets error\n");

		fclose(stream_read);
	}
	else
	{
		printf("open file error\n");
		close(ffd);
	}
}
