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
				cout<<"Pattern found at index "<< i<<endl; 
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
	char txt[] = "KUREKAR ATEET"; 
	char pat[] = "ATEET"; 
	int q = 101; //of ur choice
	search(pat, txt, q); 
	return 0; 
} 


