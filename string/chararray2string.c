#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    FILE *pf;
    char buffer[1024];
    char *opt;
 
    pf = popen("/usr/bin/iasl -v", "r");
    opt = (char*)malloc(sizeof(char)*sizeof(buffer));
    fread(buffer, sizeof(buffer), 1, pf);
    strncpy(opt, buffer+68, 8);
    printf("%s\n", opt);
     
    pclose(pf);
    return 0;
}
