#include <stdio.h>
#include <string.h>
int main()
{
	int T = 0;
	char X[11] = { 0, };
	

	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		scanf("%s", X);
		for (int i = 0; i < 10; i++)
		{
			if ((strchr(X, i + '0')) != NULL)
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}