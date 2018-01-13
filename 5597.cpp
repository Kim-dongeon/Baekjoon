#include <iostream>

using namespace std;

int main()
{
	int a[31] = { 0, };
	int b = 0;
	for (int i = 0; i < 28; i++)
	{		
		cin >> b;
		a[b] = 1;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (a[i] == 0)
		{
			cout << i << endl;
		}
	}
}