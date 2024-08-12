#include<stdio.h>
#include<string.h>
#define size 50

int main(){
	char ptext[size], ctext[size], key[9];
	prinft("Enter the key:");
	scanf("%s",key);
	printf("Enter the text:");
	scanf("%s",ptext);
	
	int ptext_len = strlen(ptext);
	int key_len = strlen(key);

	int n = ptext_len%key_len;
	n = n>0? key_len-n:0;
	for(int i=0;i<n;i++){
		ptext[ptext_len++] = ('x'+i-'a')%26 + 'a';
	}
	ptext[ptext_len] = '\0';
}
