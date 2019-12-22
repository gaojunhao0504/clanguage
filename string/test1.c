#include <stdio.h>
#include <string.h>

int main()
{
//	char *str = "-s 3,virtio-blk,b,/data/clearlinux/clearlinux.img";
//	char *opt = "3,virtio-blk,b,/data/clearlinux/clearlinux.img";
	char *opt = "7,xhci,1-1:1-2:1-3:2-1:2-2:2-3:cap=apl";
	char *str = strdup(opt);
        char *cp = strchr(str,',');
	char *emul,*config;
	emul = config = NULL;
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
	
	int bnum=1,fnum=1,snum=1;
        if (sscanf(str, "%d:%d:%d", &bnum, &snum, &fnum) != 3) {
                bnum = 0;
                if (sscanf(str, "%d:%d", &snum, &fnum) != 2) {
                        fnum = 0;
                        if (sscanf(str, "%d", &snum) != 1)
                                snum = -1;
                }
        }
	printf("bnum:%d,fnum:%d,snum:%d\n",bnum,fnum,snum);
}
