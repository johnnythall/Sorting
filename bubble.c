#include <stdio.h>
#include <sys/time.h>

int bubble(int A[], int length)
{
  int i, j, swap;
 
  for (i = 0; i < length; i++)
  {
    for (j = length; j >= i + 1; j--)
    {
      if (A[j-1] > A[j])
      {
        swap = A[j-1];
        A[j-1] = A[j];
        A[j] = swap;
      }
    }
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
	bubble(A, length-1);
	gettimeofday(&end, NULL);
	printf("%d.%06d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));

	i = 0;
	f = fopen("bubble_output.txt", "w");
	int x;
	for(x=0; x<length; x++) 
	{
	    fprintf(f, "%d\n", A[x]);
	}
	return 0;
}
  
