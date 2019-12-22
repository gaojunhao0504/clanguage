#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *str = "3,4";
	int p1, p2;
	if(sscanf(str, "%d:%d", &p1, &p2) != 2){
		fprintf(stderr, "params wrong: %s\n", str);
	}else{
		printf("p1: %d, p2: %d\n", p1, p2);
	}
}
