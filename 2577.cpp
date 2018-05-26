#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a*b*c;
	string str = to_string(sum);
	for (int i = 0; i <= 9; i++)
	{
		cout << count(str.begin(), str.end(), i+'0') << '\n';
	}

}