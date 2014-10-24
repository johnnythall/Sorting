#include <stdio.h>
#include <sys/time.h>

int insertion(int A[], int length)
{
	int i;
	int j;
	int key;
		
	for(j = 1; j < length; j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
	
	
		A[i + 1] = key;
	}
	
	
	int x;	
	for(x=0; x<length; x++) 
	{
	    printf("%d\n", A[x]);
	}
}

int main() 
{
	int a[] = {6,2,7,3,2,5,8,4,3,2,0};
	int length = 11;
	
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	insertion(a, length);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));
	
	return 0;
}