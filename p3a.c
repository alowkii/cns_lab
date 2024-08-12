#include<stdio.h>

#include<ctype.h>

#include<string.h>

#define size 50



int main(){

	char text[size], key[size], ctext[size];

	

	printf("Enter the text:");

	fgets(text, size, stdin);

	

	printf("Enter the key:");

	fgets(key, size, stdin);

	

	int i = 0;

	while(isalpha(text[i]) && isalpha(key[i])){

		ctext[i] = tolower(text[i])+tolower(key[i])-'a'*2;

		ctext[i] %= 26;

		ctext[i] += 'a';

		i++;

	}

	

	ctext[i] = '\0';

	printf("%s",ctext);

}
