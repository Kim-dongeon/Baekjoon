#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int nine[100];
int arr[100];
int ans[100];
bool flag;
void dfs(int arr[],int size,int n,int k,int index,int sum) {
	if (flag) return;
	if (sum > 100) return;

	if (k == 0) {		
		if (sum == 100) {
			for (int i = 0; i < size; i++) {
				ans[i] = nine[arr[i]];
			}
			sort(ans, ans + size);
			for (int i = 0; i < size; i++) {
				printf("%d\n", ans[i]);
			}
			flag = true;
		}		
		return;
	}
	else if (n == index) {
		return;
	}

	arr[size] = index;
	dfs(arr, size + 1, n, k - 1, index + 1, sum + nine[arr[size]]);
	dfs(arr, size, n, k, index + 1, sum);
}
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &nine[i]);
	}
	dfs(arr, 0, 9, 7, 0, 0);

}