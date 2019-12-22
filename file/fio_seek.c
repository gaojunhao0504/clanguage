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
/* fseek vs rewind */		
//		fseek(stream, 0, SEEK_SET);
		rewind(stream);
		
		int c;
		c = fgetc(stream);
		if(c == EOF)
			printf("fgetc error\n");
		else
			printf("fgetc char: %c\n", (char) c);

		char str[20];
		if(fgets(str, 20, stream))
			printf("fgets successfully, str: %s\n", str);
		else
			printf("fgets error\n");


		fclose(stream);
	}
	else
	{
		printf("open file error\n");
		close(fd);
	}

}
