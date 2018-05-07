#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(6);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int n;
			cin >> n;
			v[j] = n;
		}

		for (int j = 5; j >= 3; j--)
		{
			int temp = 0;
			temp = v[j] - v[j - 3];
			if (temp < 0)
			{
				temp = 60 + temp;
				v[j - 1]--;
			}
			v[j] = temp;
		}
		for (int j = 3; j < 6; j++)
		{
			cout << v[j] << ' ';
		}
		cout << endl;
		
	}
}