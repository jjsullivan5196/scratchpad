#include <string.h>
int printf(const char*, ...);
typedef unsigned char u8;
const u8 *str = "Hello there, world!";

int main() {
    u8 *c = (u8*)str;
    while(*c++) {}
    printf("%d %d", c - str, strlen(str));
}
