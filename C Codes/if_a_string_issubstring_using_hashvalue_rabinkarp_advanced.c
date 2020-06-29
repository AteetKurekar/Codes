#include <iostream>
#include<string.h>
using namespace std; 

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int d=strlen(txt);
	int len=strlen(txt);//13	
	int i,count=0;
	char temp[20];
	
	int p=0;
	for (int i = 0; i<M; i++) { 
		p = (d * p + pat[i]) % q; 
	}  
	
	for(i=0;i<=len;i++){
		if(txt[i]==' '){
			temp[count]='\0';
			int t=0;
			for (int k = 0; k<count; k++) { 
				t = (d * t + temp[k]) % q; 
			}
			if(t==p){
				printf("%d\t%d\t",p,t);
				printf("%s\t%s\n",pat,temp);
			}
			count=0;
			continue;
		}
		else if(txt[i]=='.'){
			temp[count]='\0';
			int t=0;
			for (int k = 0; k < count; k++) { 
				t = (d * t + temp[k]) % q; 
			}
			if(t==p){
				printf("%d\t%d\t",p,t);
				printf("%s\t%s\n",pat,temp);
			}
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

int main() 
{ 
//	char stxt[]="fruits are healthy , you should eat them regularly.";
//	char txt[]="apple is healthy fruit to eat is a good bvoy.";
	char stxt[]="Geeks forgeeks.";
	char txt[]="forgeeks.";
	int q = 123681; //of ur choice
	 
	int len=strlen(txt);//13	
	int i,count=0;
	char temp[20];
	//printf("Pattern\ttext\n");
	for(i=0;i<=len;i++){
		if(txt[i]==' '){
			temp[count]='\0';
			//printf("%s\n",temp);
			search(temp, stxt, q);
			count=0;
			continue;
		}
		else if(txt[i]=='.'){
			temp[count]='\0';
			//printf("%s\n",temp);
			search(temp, stxt, q);
			count=0;
			break;
		}
		else{
			temp[count]=txt[i];
			count++;
			continue;
		}
		
	}

	
	return 0; 
} 

