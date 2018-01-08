#include <stdio.h>
#include <stdlib.h>
int main()
{
	char str[101] = { 0, };
	char ap[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int num[26] = { 0, };
	int a = 0;

	scanf("%s", str);
	a = strlen(str);
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (ap[i] == str[j])
			{
				num[i]+=1;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", num[i]);
	}
}