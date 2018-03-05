#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string str;
	string s;
	int sum = 0;
	while (cin >> s)
	{
		str += s;
	}
	istringstream sin(str);
	
	string num;
	while (getline(sin,num,','))
	{
		sum += stoi(num);
	}
	cout << sum;
}