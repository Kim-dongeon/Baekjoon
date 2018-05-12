#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector< vector<char> > v(H,vector<char>(W));
	int ans[101][101];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			char t;
			scanf(" %c", &t);
			v[i][j] = t;
			if (t == 'c')
			{
				ans[i][j] = 0;
			}
			else {
				ans[i][j] = -1;
			}
		}
	}
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (v[i][j] == 'c')
			{
				int c = 1;
				for (int k = j + 1; k < W; k++)
				{
					if (v[i][k] == 'c')
					{
						break;
					}
					ans[i][k] = c;
					c++;
				}
			}
		}		
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}