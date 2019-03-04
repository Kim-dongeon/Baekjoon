#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[10001];
int main() {
	int N;
	cin >> N;	

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[tmp]++;
	}	
		
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
		
	}
}