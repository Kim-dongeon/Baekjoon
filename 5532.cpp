#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int L, A, B, C, D;
	cin >>L>> A >> B >> C >> D;
	if (A / C > B / D)
	{
		if (A%C ==0)
		{
			cout << L - (A / C);
		}
		else
		{
			cout << L - (A / C) - 1;
		}
	}
	else
	{
		if (B%D == 0)
		{
			cout << L - (B / D);
		}
		else
		{
			cout << L - (B / D) - 1;
		}
	}

}