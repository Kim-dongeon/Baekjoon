/*#include <iostream>
#include <cstdio>

using namespace std;

int arr[20][20];

int N;
int cnt;

bool promising(int row, int col) {

	for (int i = 0; i < row; i++) {
		if (arr[i][col] == 1) {
			return false;
		}
		if (col - i - 1 >= 0 ) {
			if (arr[row-i-1][(col - i - 1)]) {
				return false;
			}
		}

		if (col + i + 1 < N) {
			if (arr[row - i - 1][col + i + 1]) {
				return false;
			}
		}
	}

	return true;

}
void dfs(int row) {
	if (row == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (promising(row, i)) {
			arr[row][i] = 1;
			dfs(row + 1);
			arr[row][i] = 0;
		}
	}
}
int main() {
	cin >> N;
	dfs(0);
	cout << cnt;
}
*/
#include <iostream>
#include <cmath>
using namespace std;

int row[15];
int N;
int cnt;
bool promising(int q)
{
	for (int i = 1; i < q; i++)
	{
		if (row[q] == row[i] || abs(row[q]-row[i]) == abs(q-i))
		{
			return false;
		}
	}
	return true;
}
void queen(int q)
{
	if (!promising(q)) return;

	if (q == N)
	{
		cnt++;
	}
	for (int i = 0; i < N; i++)
	{
		row[q + 1] = i;
		queen(q + 1);
	}
}
int main()
{
	cin >> N;
	queen(0);
	printf("%d", cnt);
}

//----------------------------------------Àç±Í·Î Ã¼Å©
#include <iostream>

using namespace std;

int N;
int answer;
int queen[16][16];
int dx[2] = { -1,-1 };
int dy[2] = { 1,-1 };
bool dig;
void dig_check(int x, int y, int direction)
{
	if (queen[x][y] == 1)
	{
		dig = true;
		return;
	}
	x = dx[direction] + x;
	y = dy[direction] + y;
	if (x >= 0 && y >= 0 && y < N)
	{
		dig_check(x, y, direction);
	}
	else
	{
		return;
	}


}
bool check(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (queen[i][col] == 1)
		{
			return false;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 0 && ny >= 0 && ny < N)
		{
			dig_check(nx, ny, i);
		}
		if (dig)
		{
			dig = false;
			return false;
		}
	}
	return true;

}
void go(int row)
{
	if (row == N)
	{
		answer++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		queen[row][i] = 1;

		if (check(row, i))
		{
			go(row + 1);
		}

		queen[row][i] = 0;
	}

}
int main()
{
	cin >> N;
	go(0);
	cout << answer;
}