//here if the pat="a" and text="abc" ,it will not return any location.A complete pattern must be present in the string for matching i.e pat="abc". 
#include <iostream>
#include<string.h>
using namespace std; 

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int len=strlen(txt);	
	int i,count=0;
	char temp[20];
	
	int d=len;
	//hashcode of pattern
	int p=0;
	for (int i = 0; i<M; i++) { 
		p = (d * p + pat[i]) % q; 
	}  
	
	for(i=0;i<=len;i++){
		//to handle space
		if(txt[i]==' '){
			temp[count]='\0';
			int t=0;
			//hash code of a word among string
			for (int k = 0; k<count; k++) { 
				t = (d * t + temp[k]) % q; 
			}
			//if hashcode match
			if(t==p){
				printf("%d\t%d\t",p,t);
				printf("%s\t%s\n",pat,temp);
			}
			count=0;
			continue;
		}
		//at end of string
		else if(txt[i]=='.' || txt[i]=='\0'){
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
		//normal operation
		else{
			temp[count]=txt[i];
			count++;
			continue;
		}
		
	}
	
} 

int main() 
{ 
	char stxt[]="fruits are healthy , you should eat them regularly.";
	char txt[]="apple is healthy fruit to eat .";
	int q = 123681; //of ur choice
	 
	int len=strlen(txt);//13	
	int i,count=0;
	char temp[20];

	for(i=0;i<=len;i++){
		if(txt[i]==' '){
			temp[count]='\0';
			search(temp, stxt, q);
			count=0;
			continue;
		}
		else if(txt[i]=='.' || txt[i]=='\0'){
			temp[count]='\0';
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


