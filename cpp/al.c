#include <stdio.h>
typedef unsigned int u8;

const char *alpha = "@\08\0(\0|)\0003\0#\0006\0[-]\0|\0_|\0|<\0001\0[]\\/[]\0[]\\[]\0000\0|D\0(,)\0|Z\0$\0']['\0|_|\0\\/\0\\/\\/\0}{\0`/\0002";
char* ptr(u8 n){
	char* p = (char*)alpha;
	for(u8 i = 0; i < n; i++, p++)
		while(*p != 0) p++;
	return p;
}

int main() {
    char c; fread(&c, 1, 1, stdin);
    for(; c != '\n'; fread(&c, 1, 1, stdin)) {
       if(c < 65 || c > 122 || (c >= 91 && c <= 96))
        fwrite(&c, 1, 1, stdout);
       else
        printf(ptr(c < 97 ? c - 65 : c - 97));
    }
}
