5
3 30 34 5 9
OUTPUT:9534330


#include<stdio.h>
#include<string.h>
#include<math.h>
long long int max=0;
int print(int *num, int n){
	long long int number=0;
	for (int i= 0; i < n ; i++){
		printf("%d ", num[i]);
		int temp=num[i],count=0;
    //count digits,helps in forming a number
		while (temp != 0) {
	        temp /= 10;     
	        ++count;
    	}
    	number=number*pow(10,count)+num[i];
	}
	if(max<number)
		max=number;
    printf("\n");
}
int main(){
    
    int temp;
    int n=4;
//    printf("Enter n: ");
//    scanf("%d", &n);
//    printf("\nEnter Elements:\n");
//    int num[n];
	int num[]={54,546,548,60};
//    for (int i = 0 ; i < n; i++)
//        scanf("%d", &num[i]);
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < n-1; i++) {
            temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
            print(num, n);
	}
    }
    printf("\nMax: %lld",max);
 
    
    return 0;
}
