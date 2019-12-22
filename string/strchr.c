#include <stdio.h>
#include <string.h>

int main()
{
	char *str;
	char *emul,*config;
	emul = config = NULL;
	char *opt = "-s 3,virtio-blk,b,/data/clearlinux/clearlinux.img";
	str = strdup(opt);
	char *cp = strchr(str,',');
	*cp = '\0';
	emul = cp + 1;
	cp = strchr(emul, ',');
	*cp = '\0';
	config = cp + 1;
	printf("config:%s\n",config);
	if (*config == 'b') {
		printf("config:b--true\n");
	}
	printf("emul:%s\n",emul);
	return 0;
}
