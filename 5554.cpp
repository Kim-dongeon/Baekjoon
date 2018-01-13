#include <iostream>
using namespace std;
int main()
{
	int n,a=4,sum=0;
	while (a--)
	{
		cin >> n;
		sum += n;
	}
	cout << sum / 60 << endl << sum % 60;
}