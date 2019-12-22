#include<stdio.h>
#include<dirent.h>

int main()
{
	DIR *dirptr;
	struct dirent *entry;
	int i = 1;
	dirptr = opendir("/home/junhao");
	while(entry = readdir(dirptr)) {
		printf("f%d: %s\n", i,entry->d_name);
		i++;
	}
	closedir(dirptr);
	//printf("f: %s\n", entry->d_name);
	if (!entry)
		printf("entry is NULL\n");
	return 0;
}
