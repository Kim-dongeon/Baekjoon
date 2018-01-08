#include <stdio.h>

typedef struct _num {
	int num;
	int cnt;
}num;

int main()
{
	int n = 8;
	num _num[8] = { 0, };
	int i = 0;
	while (n--)
	{
		scanf("%d", &_num[i].num);
		_num[i].cnt = i+1;
		i++;
		
	}
	for (int a = 0; a < 8; a++)
	{
		for (int b = a; b < 8; b++)
		{
			if (_num[a].num < _num[b].num)
			{
				num tmp = _num[a];
				_num[a] = _num[b];
				_num[b] = tmp;
			}
		}
	}

	
	printf("%d\n", _num[0].num + _num[1].num + _num[2].num + _num[3].num + _num[4].num);
	for (int a = 0; a < 5; a++)
	{
		for (int b = a; b < 5; b++)
		{
			if (_num[a].cnt > _num[b].cnt)
			{
				num tmp = _num[a];
				_num[a] = _num[b];
				_num[b] = tmp;
			}
		}
	}
	printf("%d %d %d %d %d", _num[0].cnt, _num[1].cnt, _num[2].cnt, _num[3].cnt, _num[4].cnt);
}