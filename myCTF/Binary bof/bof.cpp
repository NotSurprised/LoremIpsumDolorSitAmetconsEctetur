#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long hashcode = 0xddaa1234;
char *keypt = NULL;

void md5bof(char *mid){
    char overflow[40];
	keypt = mid;
    printf("Give me the key : ");
    scanf("%s", overflow);
    int i = 0;
    unsigned long result = 0xddaa1234;
    int *convert = (int*)keypt;
    for(i = 0; i < 1; ++i){
        result += convert[i];
    }
    if(result != hashcode){
        printf("Flag{Catch_Me_if_U_Can}");
        system("pause");
    }
    else{
        printf("Oh no, plz try again!!\n");
	}
}


int main(){
	setvbuf(stdout, 0LL, 2, 0LL);
	setvbuf(stdin, 0LL, 1, 0LL);
	char choice;
	printf("Try me?\n");
	char blank[20] = {0};
	md5bof(blank);
}
