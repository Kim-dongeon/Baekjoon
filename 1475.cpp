#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string N;
	cin >> N;
	int _max = 0;
	int ex = 0;
	vector<char> v(N.begin(), N.end());

	for (char i = '0'; i <= '9'; i++)
	{
		int n = count(v.begin(), v.end(), i);
		if ((i == '6') || (i == '9'))
		{
			ex += n;
		}
		else
		{
			_max = max(_max, n);
		}
	}

	if (ex % 2 == 0)
	{
		ex = ex / 2;
	}
	else
	{
		ex = ex / 2 + 1;
	}
	_max = max(ex, _max);
	cout << _max;
}