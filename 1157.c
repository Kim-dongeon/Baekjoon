#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct Alpha {
	int index;
	char _alpha;
}_alpha;
int main()
{
	char ch[1000001] = { 0, };
	int len = 0;
	_alpha alpha[26] = { 0, };	

	scanf("%s", ch);
	len = strlen(ch);
	for (int i = 0; i < len; i++)
	{
		ch[i] = tolower(ch[i]);		
		alpha[ch[i] - 'a'].index++;
		alpha[ch[i] - 'a']._alpha = ch[i];
	}
	
	for (int i = 0; i < 26; i++)
	{
		for (int j = i; j < 26; j++)
		{
			if (alpha[i].index < alpha[j].index)
			{
				_alpha temp = alpha[i];
				alpha[i] = alpha[j];
				alpha[j] = temp;
			}
		}		
	}	
	
	if (alpha[0].index == alpha[1].index)
	{
		printf("?");
	}
	else
	{
		printf("%c", toupper(alpha[0]._alpha));
	}
}