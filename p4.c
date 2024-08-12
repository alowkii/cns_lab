#include<stdio.h>
#include<string.h>

int main(){
	int a[3][3]={{17,21,2},{17,18,2},{5,21,19}};
    int b[3][3]={{4,15,24},{9,17,0},{15,6,17}};
    int c[20], d[20];
    int i,j,t=0;
    char msg[20];

    printf("\nEnter the plaintext: ");
    scanf("%s",&msg);
    for(i=0;i<3;i++){
        c[i]=msg[i]-'a';
        printf("%d ",c[i]);
    }

	printf("\nThe encrypted text is : ");
    for(i=0;i<3;i++){
        t=0;
        for(j=0;j<3;j++){
            t+=(a[i][j]*c[j]);
        }
        d[i]=t%26;
        printf("%c ",d[i]+'a');
    }
    
    printf("\nThe decrypted text is : ");
    for(i=0;i<3;i++){
        t=0;
        for(j=0;j<3;j++){
            t+=(b[i][j]*d[j]);
        }
        c[i]=t%26;
        printf("%c ",c[i]+'a');
    }
	return 0;
}
