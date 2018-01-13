#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int N,cnt=0;
	long long X;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		long long b = (long long)(sqrt((double)X));
		cout << "b = " << b << endl;
		if (b*b == X)cout << 1 << " ";
		else cout << 0 << " ";
		
	}
}