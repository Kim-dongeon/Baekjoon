#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
void comb(vector<int> &v, int index, int n, int k, int size)
{
	if (k == 0)
	{
		int vowel = 0, consonant = 0;
		for (int i = 0; i < size; i++)
		{
			if (s[v[i]] == 'a' || s[v[i]] == 'e' || s[v[i]] == 'i' || s[v[i]] == 'o' || s[v[i]] == 'u')
			{
				vowel++;
			}
			else
			{
				consonant++;
			}
		}
		if (vowel >= 1 && consonant >= 2)
		{
			for (int i = 0; i < size; i++)
			{
				printf("%c", s[v[i]]);
			}
			printf("\n");
		}
	}
	else if (index == n)
	{
		return;
	}
	else {
		v[size] = index;
		comb(v, index + 1, n, k - 1, size + 1);
		comb(v, index + 1, n, k, size);
	}
}
int main()
{
	int L, C;
	cin >> L >> C;
	vector<int> v(L);
	
	for (int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;
		s += temp;
	}

	sort(s.begin(), s.end());
	comb(v, 0, C, L, 0);

}