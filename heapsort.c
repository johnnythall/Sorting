#include <stdio.h>
#include <sys/time.h>

//Still can't get heapsort to work...
int left(int i)
{
	return (2*i+ 1);
}

int right(int i)
{
	return (2*i + 2);
}

int max_heapify(int A, int i, int length)
{
	int largest;
	int l;
	int r;
	
	l = left(i);
	r = right(i);
	
	if(l <= length && A[l] > A[i])
		largest =  l;
	else
		largest = i;
	
	if (r <= length && A[r] > A[largest])
		largest = r;
	
	if(largest != i)
	{
		int swap = A[i];
		A[i] = A[largest];
		A[largest] = swap;
		max_heapify(A, largest, length);
	}
	return A;	
}
							
int build_max_heap(int A, int length)
{
	int i;
	
	for (i = length/2; i >= 0; i--)
	{
		max_heapify(A,i,length);		
	}
	return A;
}

int heapsort(int A, int length)
{
	build_max_heap(A, length);
	int i;
	for(i = length - 1; i > 0; i--){
		int swap = A[0];
		A[0] = A[i];
		A[i] = swap;
		length = length  - 1;
		max_heapify(A,0,length);
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
	heapsort(A, length);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));

	i = 0;
	f = fopen("heapsort_output.txt", "w");
	int x;
	for(x=0; x<length; x++) 
	{
	    fprintf(f, "%d\n", A[x]);
	}
	return 0;
}