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
}

int merge(int A[], int p, int q, int r)
{
	
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
 
int mergesort(int A[], int p, int r)
{
	
    if (p < r)
    {
        int q = p+(r-p)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}

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
	FILE *f;
	int a[100000];
	int num;
	f=fopen("input.txt","r");
	
	while(fscanf(f,"%d",&num)!=EOF)
	{
	   a[i]=num;
	   i++;

	}
	
	length = i;
	struct timeval start, end;
	
	//Insertion Sort
	gettimeofday(&start, NULL);
	insertion(a, length);
	gettimeofday(&end, NULL);
	printf("%d.%020d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));
	
	//Merge Sort
	gettimeofday(&start, NULL);
	mergesort(a, 0, length - 1);
	gettimeofday(&end, NULL);
	printf("%d.%020d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));
	
	//Bubble Sort
	gettimeofday(&start, NULL);
	bubble(a, length);
	gettimeofday(&end, NULL);
	printf("%d.%020d\n", (int)(end.tv_sec-start.tv_sec), (int)(end.tv_usec-start.tv_usec));
	
	return 0;
}