#include <stdio.h>

//int main()
//{
//	int loop = 0,j=0;
//	scanf("%d", &loop);
//	for (int i = 0; i < loop; i++)
//	{
//		int a = 0, b = 0;
//		scanf("%d %d", &a, &b);
//		for ( j = 1; j%a != 0 || j%b != 0; j++);
//		printf("%d\n", j);		
//	}
//}

//int gcd(int a, int b)
//{
//	if (b == 0)
//	{
//		return a;
//	}
//	gcd(b, a % b);
//}
//int lcm(int a, int b)
//{
//	return (a*b)/ gcd(a, b);
//}
//int main()
//{	int loop = 0, j = 0;
//	scanf("%d", &loop);
//	for (int i = 0; i < loop; i++)
//	{
//		int a = 0, b = 0;
//		scanf("%d %d", &a, &b);
//		printf("%d\n",lcm(a, b));
//	}
//}

//#include <stdio.h>

//int main()
//{
//	int loop = 0,j=0;
//	scanf("%d", &loop);
//	for (int i = 0; i < loop; i++)
//	{
//		int a = 0, b = 0;
//		scanf("%d %d", &a, &b);
//		for ( j = 1; j%a != 0 || j%b != 0; j++);
//		printf("%d\n", j);		
//	}
//}

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}
int main()
{
	int loop = 0, j = 0;
	scanf("%d", &loop);
	for (int i = 0; i < loop; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", lcm(a, b),gcd(a,b));
	}
}