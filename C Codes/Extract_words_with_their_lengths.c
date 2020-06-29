#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
	char txt[]="Ateet Kurekar is a good boy.";
	int len=strlen(txt);//13	
	int i,count=0;
	char temp[20];
	printf("String\tlength\n");
	for(i=0;i<=len;i++){
		if(txt[i]==' '){
			temp[count]='\0';
			printf("%s\t%d\n",temp,strlen(temp));
			count=0;
			continue;
		}
		else if(txt[i]=='.'){
			temp[count]='\0';
			printf("%s\t%d",temp,strlen(temp));
			count=0;
			break;
		}
		else{
			temp[count]=txt[i];
			count++;
			continue;
		}
		
	}
}
