#include <stdio.h>
#include <sys/time.h>

int merge(int A[], int p, int q, int r){
	
    int i;
	int j;
	int k;
    int n1 = q - p + 1;
    int n2 =  r - q;
    int L[n1+1];
	int R[n2+1];
	
	L[n1] = 99999999;
	R[n2] = 99999999;
 
    for(i = 0; i < n1; i++)
	{
        L[i] = A[p + i];
	}
	
    for(j = 0; j < n2; j++){
        R[j] = A[q + 1+ j];
	}
	
    i = 0;
    j = 0;
    k = p;
	
    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}
 
int mergesort(int A[], int p, int r){
	
    if (p < r)
    {
        int q = p+(r-p)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
	int i;
	for(i=0; i<r+1; i++) {
	    printf("%d\n", A[i]);
	}
}
 

int main(){
    int A[] = {12, 13, 13, 5, 8, 7};
    int length = 6;
  
    mergesort(A, 0, length - 1);
 
    return 0;
}