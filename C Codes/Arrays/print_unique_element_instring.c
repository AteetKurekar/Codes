
confusion here is like comparison between 0's but still it will preserve uniqueness as replacing with 0's with 0's again.
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	char a[]="Ateet Kurekar";
	for(int i=0;i<strlen(a)-1;i++){
		for(int j=i+1;j<strlen(a);j++){
			if(a[i]==a[j]){
				a[j]='0';
			}
		}
	}
for(int i=0;i<strlen(a);i++){
	if(a[i]!='0' && a[i]!=' ')
		printf("%c ",a[i]);
}

}

OR
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
	char a[]="Ateet Kurekar";
	for(int i=0;i<strlen(a);i++){
		int flag=0;
		//checking previous elements
		for(int j=0;j<i;j++){
			if(a[j]==a[i]){
				flag=1;
			}
		}
		if(flag==0){
			if(a[i]!=' '){
				printf("%c ",a[i]);
			}
		}		
	}	
}

OR
other solution:Hashmaps
