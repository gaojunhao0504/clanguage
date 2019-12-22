#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	int fd;
/* open file */
	fd = open("/home/tmp", O_RDWR | O_TRUNC ,__O_DIRECT);
	if(fd == -1)
		printf("this file read error\n");
	else
		printf("open file successfully\n");

/* write file */
/***
	char *ch = "..."
	sizeof(ch) = 8
***/
	char ch[] = "first write file";
	ssize_t nw;
	nw = write(fd, ch, sizeof(ch));
	if(nw == -1)
		printf("write file error, nw: %ld \n", nw);
	else
		printf("write file successfully, nw:%ld\n", nw);

/* seek file */
	lseek(fd, 1, SEEK_SET);

/* read file */
/***
	buff will output to \n
***/
	char buff[100];
	ssize_t nr;
	nr = read(fd, buff, sizeof(buff));
	printf("read nr:%ld\n", nr);
	if(nr != -1)
		printf("read file successfully, buff:%s\n", buff);
	else
		printf("read file error\n");

/* pwrite file */
	char chp[] = "second pwrite file";
	ssize_t nwp;
	nwp = pwrite(fd, chp, sizeof(chp), 18);
	if(nwp == -1)
		printf("pwrite file error, nwp: %ld \n", nwp);
	else
		printf("pwrite file successfully, nwp:%ld\n", nwp);

/* pread file */
        char buff_p[100];
        ssize_t nrp;
        nrp = pread(fd, buff_p, sizeof(buff_p), 19);
        printf("pread nrp:%ld\n", nrp);
        if(nrp != -1)
                printf("pread file successfully, buff_p:%s\n", buff_p);
        else
                printf("pread file error\n");

/* truncate file */
	int ret;
	ret = truncate("/home/tmp", 10);
	if(ret == -1)
		printf("truncate error\n");

        char buff_p_2[100];
        ssize_t nrp_2;
        nrp_2 = pread(fd, buff_p_2, sizeof(buff_p_2), 0);
        printf("pread nrp_2:%ld\n", nrp_2);
        if(nrp_2 != -1)
                printf("pread file successfully, buff_p_2:%s\n", buff_p_2);
        else
                printf("pread file error\n");

	close(fd);
	return 0;
}


