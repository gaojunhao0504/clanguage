#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[10];
	u_char t;
	t = 017;
	int ret = snprintf(str,10,"a%s","gdsksfdji");
	printf("ret:%d, str:%s str.size:%d, t:%02X\n",ret,str,sizeof(str),t);
	int h = 7;
	if(h >= 7)
		printf("yes\n");
	return 0;
}
