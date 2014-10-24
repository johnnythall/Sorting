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
}
 


int main() 
{
	int i=0;
	int length;
	int A[999999];
	int num;
	FILE *f;
	f = fopen("input.txt","r");

	while(fscanf(f,"%d",&num)!=EOF)
	{
	   A[i]=num;
	   i++;

	}
	length = i;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	mergesort(A, 0, length - 1);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));

	i = 0;
	f = fopen("merge_output.txt", "w");
	int x;
	for(x=0; x<length; x++) 
	{
	    fprintf(f, "%d\n", A[x]);
	}
	return 0;
}
  