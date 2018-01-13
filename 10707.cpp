#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int A, B, C, D, P,x,y,s=0;
	cin >> A >> B >> C >> D>>P;
	cout << min(A*P,(P>C)?(B+(P-C)*D):B);
}