#include <stdio.h>
#include <string.h>

void fizzbuzz(int num, char str[]) {
	strcpy(str, "");

	if(!(num % 3))
		strcat(str, "Fizz");
	if(!(num % 5))
		strcat(str, "Buzz");
	if(!strlen(str))
		sprintf(str, "%d", num);
}

main() {
	char str[17] = "";

	for(int i = 0; i < 32; i++) {
		fizzbuzz(i, str);
		printf("%s\n", str); 
	}
}
