#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (strcmp(str.c_str(),"END")==0) {
			break;
		}

		int str_len = str.size();
		for (int i = 0; i < str_len/2; i++) {
			char temp = str[i];
			str[i] = str[str_len - i - 1];
			str[str_len - i - 1] = temp;
		}

		cout << str << endl;
	}
}