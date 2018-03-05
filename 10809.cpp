#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for (char i = 'a'; i <='z';i++ )
	{
		auto it = find(str.begin(), str.end(), i);
		if (it == str.end())
		{
			cout << "-1" << ' ';
		}
		else
		{
			cout << (it - str.begin()) << ' ';
		}
	}
}