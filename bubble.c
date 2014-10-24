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
	for(i=0; i<length; i++) {
    	printf("%d\n", A[i]);
	}
}

int main()
{
    int A[] = {12, 13, 13, 5, 8, 7};
    int length = 6;
  
    bubble(A, length);
 
    return 0;
}