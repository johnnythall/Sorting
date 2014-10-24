#include <stdio.h>
#include <sys/time.h>

int partition(int A[], int p, int r)
{
	int i, j;
	i = p - 1;
	int x = A[r];
	
	for(j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i++;
			int swap = A[i];
			A[i] = A[j];
			A[j] = swap;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = x;
	
	return i + 1;
}

int quicksort(int A[], int p, int r)
{
	if(p < r)
	{
		int q = partition(A,p,r);
		quicksort(A,p, q - 1);
		quicksort(A,q + 1,r);
	}
	return A;
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
	quicksort(A, 0, length-1);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));

	i = 0;
	f = fopen("quicksort_output.txt", "w");
	int x;
	for(x=0; x<length; x++) 
	{
	    fprintf(f, "%d\n", A[x]);
	}
	return 0;
}
