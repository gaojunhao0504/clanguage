#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static int basl1(int a, int b){
	printf("basl1 a=%d, b=%d\n",a,b);
}
static int basl2(int a, int b){
        printf("basl2 a=%d, b=%d\n",a,b);
}
static int basl3(int a, int b){
        printf("basl3 a=%d, b=%d\n",a,b);
}

static struct {
	int (*joy)(int a, int b);
	bool valid;
} basl[] = {
	{basl1, true},
	{basl2, false},
	{basl3, true}
};

int main()
{
//	printf("basl2 %d\n", basl[1].valid);
//	basl[1].valid = true;
//	printf("basl2 %d\n", basl[1].valid);
//	return 0;
	basl[1].joy(1,2);
}
