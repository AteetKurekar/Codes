Input : A[] = {1, 2, 3, 4, 5}
Output : 4
The valid triplets are:
(1, 2, 3), (1, 3, 4), (1, 4, 5), (2, 3, 5)

Input : A[] = {1, 1, 1, 2, 2}
Output : 6


#include<stdlib.h>
#include<stdio.h>
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}

int main() 
{ 
	int a[] = {5,9,8,4,1,2,3,7};
	int n=sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, n - 1); 
	
	int count=0;
	for(int i=2;i<n;i++){
		for(int j=0;j<i-1;j++){
			for(int k=j+1;k<i;k++){
				if(a[i]==a[j]+a[k]){
					count++;
					printf("%d %d :%d\n",a[j],a[k],a[i]);
				}
					
			}
		}
	}
	printf("\ncount:%d",count);
	
} 
