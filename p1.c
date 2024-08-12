#include<stdio.h>

int main(){
	char str[] = "Hello world";
	int k = 0;
	
	printf("\nAND:\n");
	while(str[k] != '\0'){
		printf("%d\t",str[k] & 127);
		k++;
	}
	
	k = 0;
	
	printf("\nOR:\n");
	while(str[k] != '\0'){
		printf("%d\t",str[k] | 127);
		k++;
	}
	
	k = 0;
	
	printf("\nXOR:\n");
	while(str[k] != '\0'){
		printf("%d\t",str[k] ^ 127);
		k++;
	}
}
