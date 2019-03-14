#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int ans = -1;
int N, M;
int arr[501][501];

bool L[3][2] = { {1,0},{1,0},{1,1} };//ㄴ
bool L1[3][2] = { { 0,1 },{ 0,1 },{ 1,1 } }; //_ㅣ
bool L2[3][2] = { { 1,1 },{ 1,0 },{ 1,0 } };	//ㅣ-
bool L3[3][2] = { { 1,1 },{ 0,1 },{ 0,1 } };	//ㄱ

bool L4[2][3] = { {0,0,1},{1,1,1} };
bool L5[2][3] = { { 1,0,0 },{ 1,1,1 } };
bool L6[2][3] = { { 1,1,1 },{ 1,0,0 } };
bool L7[2][3] = { { 1,1,1 },{ 0,0,1 } };


bool K[3][2] = { {1,0},{1,1},{0,1} };
bool K1[3][2] = { { 0,1 },{ 1,1 },{ 1,0 } };
bool K2[2][3] = { {0,1,1},{1,1,0} };
bool K3[2][3] = { { 1,1,0 },{ 0,1,1 } };

bool R[2][3] = { {1,1,1},{0,1,0} };
bool R1[3][2] = { { 0,1},{ 1,1},{ 0,1} };
bool R2[3][2] = { { 1,0 },{ 1,1},{ 1,0} };
bool R3[2][3] = { { 0,1,0 },{ 1,1,1 } };
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	//사각형
	for (int i = 0; i <= N-2; i++) {
		for (int j = 0; j <= M-2; j++) {
			int sum = 0;
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					sum += arr[a+i][b+j];
				}
			}
			ans = max(ans, sum);
		}
	}
	
	//일자
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M-4; j++) {
			int sum = 0;			
			for (int a = 0; a < 4; a++) {
				sum += arr[i][a+j];
				
			}
			ans =max(ans, sum);
			
		}
	}
	for (int i = 0; i <= N - 4; i++) {			
		for (int j = 0; j < M; j++) {	
			int sum1 = 0;
			for (int a = 0; a < 4; a++) {
				sum1 += arr[i+a][j];
			}
			ans = max(ans, sum1);
		}		
	}


	for (int i = 0; i <= N-3; i++) {
		for (int j = 0; j <= M-2 ; j++) {
			int sum = 0;
			int sum1 = 0;
			int sum2 = 0;
			int sum3 = 0;
			int sum4 = 0;
			int sum5 = 0;
			

			
			int sum10 = 0;
			int sum11 = 0;

		

			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 2; b++) {
					if (L[a][b] == 1) {
						sum += arr[i + a][j + b];
					}
					if (L1[a][b] == 1) {
						sum1 += arr[i + a][j + b];
					}if (L2[a][b] == 1) {
						sum2 += arr[i + a][j + b];
					}if (L3[a][b] == 1) {
						sum3 += arr[i + a][j + b];
					}
					if (K[a][b] == 1) {
						sum4 += arr[i + a][j + b];
					}
					if (K1[a][b] == 1) {
						sum5 += arr[i + a][j + b];
					}
					
				
					if (R1[a][b] == 1) {
						sum10 += arr[i + a][j + b];
					}
					if (R2[a][b] == 1) {
						sum11 += arr[i + a][j + b];
					}
				}
			}
			
			ans = max(ans, sum);
			ans = max(ans, sum1);
			ans = max(ans, sum2);
			ans = max(ans, sum3);
			ans = max(ans, sum4);
			ans = max(ans, sum5);
			
			
			ans = max(ans, sum10);
			ans = max(ans, sum11);
			
		}
	}

	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			int sum12 = 0; //L4
			int sum13 = 0;
			int sum14 = 0;
			int sum15 = 0;
			int sum6 = 0;
			int sum7 = 0;
			int sum8 = 0;
			int sum9 = 0;
			for (int a = 0; a <2; a++) {
				for (int b = 0; b < 3; b++) {
					if (L4[a][b] == 1) {
						sum12 += arr[i + a][j + b];
					}if (L5[a][b] == 1) {
						sum13 += arr[i + a][j + b];
					}if (L6[a][b] == 1) {
						sum14 += arr[i + a][j + b];
					}if (L7[a][b] == 1) {
						sum15 += arr[i + a][j + b];
					}if (K2[a][b] == 1) {
						sum6 += arr[i + a][j + b];
					}
					if (K3[a][b] == 1) {
						sum7 += arr[i + a][j + b];
					}
					if (R[a][b] == 1) {
						sum8 += arr[i + a][j + b];
					}
					if (R3[a][b] == 1) {
						sum9 += arr[i + a][j + b];
					}
				}
			}
			ans = max(ans, sum12);
			ans = max(ans, sum13);
			ans = max(ans, sum14);
			ans = max(ans, sum15);
			ans = max(ans, sum6);
			ans = max(ans, sum7);
			ans = max(ans, sum8);
			ans = max(ans, sum9);
		}
	}
	cout << ans;
}