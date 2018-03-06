#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> s;
	int N, n = 0, m = 0;
	int M = 0;
	scanf("%d", &N);

	while (N--)
	{
		scanf("%d", &n);
		s.push_back(n);
	}	
	scanf("%d", &M);
	sort(s.begin(), s.end());
	while (M--)
	{
		scanf("%d", &m);		
		auto lp = lower_bound(s.begin(), s.end(), m);
		auto rp = upper_bound(s.begin(), s.end(), m);
		printf("%d ", rp-lp);
	}
}