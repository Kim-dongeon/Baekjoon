#include <iostream>
#include <string>

using namespace std;

int main()
{
	int sum = 0;
	string str;
	
	while (getline(cin, str, ','))
	{
		sum += stoi(str);
	}
	cout << sum;
}