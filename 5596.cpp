#include <iostream>
using namespace std;
int main()
{
	int a,x=0,y=0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		x += a;
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		y += a;
	}
	cout << ((x >= y) ? x : y);
}