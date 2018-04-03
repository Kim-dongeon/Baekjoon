#include <iostream>
#include <vector>
//#include <cmath>
#include <algorithm>
using namespace std;

bool broken[10];

int possible(int _dest)
{
	int len=0;
	if (_dest == 0)
	{
		return broken[0] ? 0 : 1;
	}
	while (_dest)
	{
		if (broken[_dest % 10] == true)	return 0;
		_dest = _dest / 10;
		len++;
	}
	return len;
}
int main()
{
	int now = 100;
	//int cnt = 10000000;
	int dest;
	cin >> dest;
	int cnt= now - dest;
	if (cnt < 0)
	{
		cnt = -cnt;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		broken[t] = true;
	}

	for (int i = 0; i <= 1000000; i++)
	{
		int c = i;
		int len = possible(c);
		if (len)
		{
			int p = dest - c;
			if (p < 0)
			{
				p = -p;
			}
			int temp = len + p;			
			if (cnt > temp)
			{
				cnt = temp;
			}
			//cnt = min(temp, cnt);		
		}
	}
	/*if (cnt > updown_only)
	{
		cnt = updown_only;
	}*/
	cout << cnt;
	//cout << min(cnt,updown_only);

}