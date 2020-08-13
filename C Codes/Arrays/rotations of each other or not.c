    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.


// C program to reverse a string 
#include <stdio.h> 
#include<stdlib.h>
#include<string.h>

int main(){
	char a[]="amazon";
	char b[]="azonam";
	strcat(a,a);
	if(strstr(a,b))
		printf("Yes");
	else
		printf("No");
	
}
