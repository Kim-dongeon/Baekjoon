#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int *ptr =NULL;
	float *n_p = NULL,sum=0.0;
	int large =0;

	scanf("%d", &N);
	
	ptr = (int *)malloc(sizeof(int )*N);
	n_p = (float *)malloc(sizeof(float)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &ptr[i]);
		if (large < ptr[i])
		{
			large = ptr[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		n_p[i] = (float)ptr[i] / large * 100;	
		sum += n_p[i];
	}
	sum = sum / N;
	printf("%.2f", sum);


	free(ptr);
}