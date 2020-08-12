#include<stdio.h>  
#include<string.h>  

void generatePermutation(int *str,const int start, int end)  {  
  int temp;  
  int i,j;  
  for(i = start; i < end-1; ++i){  
	  for(j = i+1; j < end; ++j){  
		   //Swapping the string by fixing a character  
		    temp = str[i];  
		  	str[i] = str[j];  
		    str[j] = temp;  
		    //Recursively calling function generatePermutation() for rest of the characters  
		  	generatePermutation(str , i+1 ,end);  
		    //Backtracking and swapping the characters again  
		    temp = str[i];  
		    str[i] = str[j];  
		    str[j] = temp;  
	  }  
  }  
  //Print the permutations 
  for(int i=0;i<4;i++){
  	printf("%d ",str[i]); 
  }
  printf("\n"); 
   
}
int main()  {  
  int str[] = {58,546,548,54};//"123";  
  int n =4;//strlen(str);  
  printf("All the permutations of the string are: \n");  
  generatePermutation(str,0,n);  
}  
