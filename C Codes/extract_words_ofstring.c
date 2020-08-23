//here IP point is we forget is a character is declared in '' and string in ""
//mistake i made here was txt[i]==" " which should be txt[i]==' '
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
	char txt[]="Ateet Kurekar is a good boy.";
	int len=strlen(txt);//13	
	int i;
	
	for(i=0;i<=len;i++){
		if(txt[i]==' '){
			printf("\n");
			continue;
		}
		else if(txt[i]=='.'){
			break;
		}
		printf("%c",txt[i]);
		continue;
	}
}
