#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char *arg = "asdfg";
	size_t len = strnlen(arg, 5);
	char str[5];
	strncpy(str, arg, len + 1);
	printf("str: %s\n", str);
	return 0;
}
