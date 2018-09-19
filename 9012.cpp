#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int len = str.size();
		if (str[0] != '(' || str[len - 1] != ')')
		{
			cout << "NO" << endl;
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '(')
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
			if (cnt < 0)
			{
				break;
			}
		}

		if (cnt == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}