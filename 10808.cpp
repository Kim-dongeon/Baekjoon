#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (char a = 'a'; a <= 'z'; a++)
	{
		cout << count(str.begin(), str.end(), a)<<' ';
	}
}