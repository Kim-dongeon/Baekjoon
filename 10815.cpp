#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int N,n=0,m=0;
	int M = 0;
	scanf("%d", &N);

	while (N--)
	{
		scanf("%d", &n);
		s.insert(n);
	}
	pair<set<int>::iterator, bool> result;
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &m);
		result= s.insert(m);
		printf("%d ", !result.second);		
	}
}