#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1,s2,s3,s4;
	string num1, num2;
	cin >> s1 >> s2 >> s3 >> s4;
	num1 = s1 + s2;
	num2 = s3 + s4;

	int n1 = stoi(num1);
	int n2 = stoi(num2);
	cout << n1 + n2;
}