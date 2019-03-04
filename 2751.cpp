#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[1000001];
int sorted[100001];
void findLocation(int curIdx, int lastIdx) {
	int left_idx = curIdx * 2;
	int right_idx = left_idx + 1;
	int min_idx = curIdx;
	
	if (left_idx <= lastIdx && arr[left_idx] < arr[min_idx]) {
		min_idx = left_idx;
	}
	if (right_idx <= lastIdx && arr[right_idx] < arr[min_idx]) {
		min_idx = right_idx;
	}

	if (min_idx != curIdx) {
		swap(arr[min_idx], arr[curIdx]);
		findLocation(min_idx, lastIdx);
	}
}
void heapify(int lastIdx) {
	int cur_idx = lastIdx / 2;

	while (cur_idx >= 1) {
		findLocation(cur_idx,lastIdx);
		cur_idx--;
	}
}

int removeRoot(int lastIdx) {
	int ret = arr[1];
	arr[1] = arr[lastIdx];
	arr[lastIdx] = 0;

	findLocation(1, lastIdx - 1);
	return ret;
}

void heapSort(int lastIdx) {
	int n = lastIdx;
	heapify(n);
	for (int i = 0; i < n; i++) {
		sorted[i] = removeRoot(lastIdx--);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i+1]);
	}
	
	heapSort(N);

	for (int i = 0; i < N; i++) {
		printf("%d\n", sorted[i]);
	}
}