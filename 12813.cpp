#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<100000> bs1;
	bitset<100000> bs2;

	cin >> bs1 >> bs2;

	cout << (bs1 & bs2) << '\n';
	cout << (bs1 | bs2) << '\n';
	cout << (bs1 ^ bs2) << '\n';
	cout << (~bs1) << '\n';
	cout << (~bs2) << '\n';

}