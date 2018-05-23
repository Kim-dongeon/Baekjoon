#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int r, e, c;
		cin >> r >> e >> c;
		if (e - c >= 0 && e - c > r)
		{
			printf("advertise\n");
		}
		else if (e-c == r)
		{
			printf("does not matter\n");
		}
		else
		{
			printf("do not advertise\n");
		}
	}
}