#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a=0, b=0;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}