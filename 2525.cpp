#include <iostream>

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	int time;
	cin >> time;

	int start = 60 * h + m;
	time = time + start;

	cout << time / 60 % 24 << ' ' << (time % 60)  ;

}