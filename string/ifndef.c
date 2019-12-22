#include <stdio.h>
#define AMD

int main()
{
#ifndef AMD
	printf("intel\n");
#else
	printf("amd\n");
#endif
}
