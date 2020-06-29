//here if the pat="a" and text="abc" ,it will give the location of a in abc i.e 0
#include <iostream>
#include<string.h>
using namespace std; 
#define d 256 

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt);  
	int p = 0,t = 0; // intialize hash value for txt and pat 

	//get the hash value of starting m elements of both text and pattern
	for (int i = 0; i < M; i++) { 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// to traverse the text from beginning
	for (int i = 0; i <= N - M; i++) 
	{ 
		int j;
		//if the pattern matches confirm by matching element bu element
		//in some case it happens that the hash value matches but elements are different
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) //will break if any one element dont match
					break; 
			} 

			//if traversing is done then j will become equal to m
			if (j == M) 
				cout<<pat<<": Pattern found at index "<< i<<endl; 
		} 

		
		//Calculate hash value of next m elements starting from i+1 
		if ( i < N-M ){
			t=0;
			for(int k=1;k<=M;k++){
				t=(d*t + txt[i+k])%q;
			}
			
		} 
	} 
} 

int main() 
{ 
	char stxt[]="fruits are healthy , you should eat them regularly.";
	char txt[]="apple is healthy fruit to eat.";
	int q = 101; //of ur choice
	 
	int len=strlen(txt);//13	
	int i,count=0;
	char temp[20];
	//printf("String\tlength\n");
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

