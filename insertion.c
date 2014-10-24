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
	insertion(A, length);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));
	
	i = 0;
	f = fopen("insertion_output.txt", "w");
	int x;
	for(x=0; x<length; x++) 
	{
	    fprintf(f, "%d\n", A[x]);
	}
	return 0;
}