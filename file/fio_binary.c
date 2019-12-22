#include <stdio.h>
int main()
{
	FILE *in, *out;
	struct pirate{
		char name[100];
		long grade;
		int age;
	} p, stu={"michael",5,38};
	
	out = fopen("/home/stu","w");
	if(!out)
	{
		perror("fopen");
		return 1;
	}
	if(!fwrite(&stu,sizeof(struct pirate),1,out))
	{
		perror("fwrite");
		return 1;
	}
	if(fclose(out))
	{
		perror("fclose");
		return 1;
	}

	in = fopen("/home/stu","r");
	if(!in)
	{
		perror("fopen");
		return 1;
	}
	if(!fread(&p,sizeof(struct pirate),1,in))
	{
		perror("fopen");
		return 1;
	}
	if(fclose(in))
	{
		perror("fclose");
		return 1;
	}
	printf("p.name:%s,p.grade:%ld,p.age:%d\n",p.name,p.grade,p.age);
	return 0;
}
