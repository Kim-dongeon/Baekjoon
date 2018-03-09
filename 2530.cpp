#include <iostream>

using namespace std;

int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	int time;
	cin >> time;

	int start = 3600 * h + 60 * m + s;
	time = time + start;

	cout << time / 3600%24 << ' ' << (time % 3600) / 60 <<' ' << (time % 3600 % 60);

}