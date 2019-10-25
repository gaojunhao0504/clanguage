#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    FILE *pf;
    char buffer[1024];
    char * arra[10];
    char *opt;
    int i=0;
 
    pf = popen("/usr/bin/iasl -v", "r");
    fread(buffer, sizeof(buffer), 1, pf);
    opt = strtok(buffer, " ");
    while (opt  != NULL) {
	    arra[i] = (char*)malloc(100*sizeof(char));
	    strcpy(arra[i], opt);
	    opt = strtok( NULL, " ");
	    i++;
    }
    printf("%s\n", arra[7]);
     
    pclose(pf);
    return 0;
}
