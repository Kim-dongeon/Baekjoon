#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char arr[6][3][3];	//»ö,x,y;
char color[6] = { 'w','g','r','b','o','y' };
void init_arr() {
	for (int i = 0; i < 6; i++) {
		int co = color[i];
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				arr[i][j][k] = co;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		init_arr();

		for (int i = 0; i < n; i++) {
			char d, circle;
			scanf(" %c %c", &d, &circle);

			if (d == 'U') {//Èò
				//1,2,3,4 º¯È­
				char tmp_arr[3][3];
				if (circle == '+') {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[0][2 - b][a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[0][b][2-a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[0][a][b] = tmp_arr[a][b];
					}
				}
				
				char tmp[3] = { arr[2][0][0],arr[2][0][1] ,arr[2][0][2] };
				if (circle == '+') {
					for (int k = 0; k < 3; k++) {
						arr[2][0][k] = arr[3][0][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][0][k] = arr[4][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][0][k] = arr[1][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[1][0][k] = tmp[k];
					}
				}
				else {
					for (int k = 0; k < 3; k++) {
						arr[2][0][k] = arr[1][0][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[1][0][k] = arr[4][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][0][k] = arr[3][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][0][k] = tmp[k];
					}
				}
			}
			else if (d == 'D') {//³ë
				char tmp_arr[3][3];
				if (circle == '+') {					
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[5][b][2 - a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[5][2 - b][a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[5][a][b] = tmp_arr[a][b];
					}
				}

				char tmp[3] = { arr[2][2][0],arr[2][2][1] ,arr[2][2][2] };
				if (circle == '+') {	
					for (int k = 0; k < 3; k++) {
						arr[2][2][k] = arr[1][2][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[1][2][k] = arr[4][2][2 - k];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][2][k] = arr[3][2][2 - k];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][2][k] = tmp[k];
					}
				}
				else {		
					for (int k = 0; k < 3; k++) {
						arr[2][2][k] = arr[3][2][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][2][k] = arr[4][2][2 - k];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][2][k] = arr[1][2][2 - k];
					}
					for (int k = 0; k < 3; k++) {
						arr[1][2][k] = tmp[k];
					}
				}
			}
			else if (d == 'F') {//»¡	
				char tmp_arr[3][3];
				if (circle == '+') {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[2][2 - b][a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[2][b][2 - a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[2][a][b] = tmp_arr[a][b];
					}
				}
				char tmp[3] = { arr[1][0][2],arr[1][1][2] ,arr[1][2][2] };
				if (circle == '+') {
					for (int k = 0; k < 3; k++) {
						arr[1][k][2] = arr[5][2][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][2][k] = arr[3][2-k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][k][0] = arr[0][2][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[0][2][k] = tmp[2-k];
					}
				}
				else {
					for (int k = 0; k < 3; k++) {
						arr[1][k][2] = arr[0][2][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[0][2][k] = arr[3][k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][k][0] = arr[5][2][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][2][k] = tmp[k];
					}					
				}
			}
			else if (d == 'B') {//¿À
				char tmp_arr[3][3];
				if (circle == '+') {					
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[4][b][2 - a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[4][2 - b][a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[4][a][b] = tmp_arr[a][b];
					}
				}
				char tmp[3] = { arr[1][0][0],arr[1][1][0] ,arr[1][2][0] };
				if (circle == '+') {
					for (int k = 0; k < 3; k++) {
						arr[1][k][0] = arr[0][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[0][0][k] = arr[3][k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][k][2] = arr[5][0][2-k];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][0][k] = tmp[k];
					}
				}
				else {
					for (int k = 0; k < 3; k++) {
						arr[1][k][0] = arr[5][0][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][0][k] = arr[3][2-k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[3][k][2] = arr[0][0][k];
					}
					for (int k = 0; k < 3; k++) {
						arr[0][0][k] = tmp[2-k];
					}
				}
			}
			else if (d == 'L') {//ÃÊ
				char tmp_arr[3][3];
				if (circle == '+') {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[1][2 - b][a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[1][b][2 - a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[1][a][b] = tmp_arr[a][b];
					}
				}
				char tmp[3] = { arr[0][0][0],arr[0][1][0] ,arr[0][2][0] };
				if (circle == '+') {
					for (int k = 0; k < 3; k++) {
						arr[0][k][0] = arr[4][2-k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][k][0] = arr[5][k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][k][0] = arr[2][2-k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[2][k][0] =tmp[k];
					}
				}
				else {
					for (int k = 0; k < 3; k++) {
						arr[0][k][0] = arr[2][k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[2][k][0] = arr[5][2-k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][k][0] = arr[4][k][0];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][k][0] = tmp[2-k];
					}
				}
			}
			else if (d == 'R') {//ÆÄ
				char tmp_arr[3][3];
				if (circle == '+') {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[3][2 - b][a];
						}
					}
				}
				else {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							tmp_arr[a][b] = arr[3][b][2 - a];
						}
					}
				}
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						arr[3][a][b] = tmp_arr[a][b];
					}
				}
				char tmp[3] = { arr[0][0][2],arr[0][1][2] ,arr[0][2][2] };
				if (circle == '+') {
					for (int k = 0; k < 3; k++) {
						arr[0][k][2] = arr[2][k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[2][k][2] = arr[5][2-k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][k][2] = arr[4][k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][k][2] = tmp[2-k];
					}
				}
				else {
					for (int k = 0; k < 3; k++) {
						arr[0][k][2] = arr[4][2-k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[4][k][2] = arr[5][k][2];
					}
					for (int k = 0; k < 3; k++) {
						arr[5][k][2] = arr[2][2-k][2];
					}				
					for (int k = 0; k < 3; k++) {
						arr[2][k][2] = tmp[k];
					}
				}
			}


			/*for (int k = 0; k < 6; k++) {
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						printf("%c", arr[k][a][b]);
					}
					printf("\n");
				}
				cout << endl;
			}*/
			
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", arr[0][i][j]);
			}
			printf("\n");
		}
		
	}
}