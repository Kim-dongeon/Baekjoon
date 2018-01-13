#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i = 0;
	while (true)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (!L && !P && !V)return 0;
		i++;
		cout << "Case " << i << ": " << V / P*L + min(L, V%P)<<endl;
	}
}