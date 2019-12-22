#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = "hh-ss";
	char *s;
	s = strsep(&str, "-");
	printf("s: %s\n", s);
	return 0;
}
