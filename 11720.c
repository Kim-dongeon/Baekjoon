#include <stdio.h>
#include <string.h>

int main()
{
	int N = 0, sum=0;
	char ch[101] = { 0, };
	scanf("%d", &N);
	scanf("%s", ch);
	for (int i = 0; i < strlen(ch); i++)
	{	
		sum += ch[i] - '0';
	}
	printf("%d\n", sum);
}

//-----------------------------------------
//#include <stdio.h>
//
//int main()
//{
//	int N, x = 0, sum = 0;
//	scanf("%d", &N);
//	while (N--)
//	{
//		scanf("%1d", &x);
//		sum += x;
//	}
//	printf("%d", sum);
//}