#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	bool ap[52] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		int pos;
		switch (x[1]) {
			case 'A':
				pos = 0;
				break;
			case '2':
				pos = 1;
				break;
			case '3':
				pos = 2;
				break;
			case '4':
				pos = 3;
				break;
			case '5':
				pos = 4;
				break;
			case '6':
				pos = 5;
				break;
			case '7':
				pos = 6;
				break;
			case '8':
				pos = 7;
				break;
			case '9':
				pos = 8;
				break;
			case 'T':
				pos = 9;
				break;
			case 'J':
				pos = 10;
				break;
			case 'Q':
				pos = 11;
				break;
			case 'K':
				pos = 12;
				break;
		}
		pos++;
		switch (x[0]) {
			case 'D':
				pos--;
				break;
			case 'C':
				pos += 13;
				pos--;
				break;
			case 'H':
				pos += 26;
				pos--;
				break;
			case 'S':
				pos += 39;
				pos--;
				break;
		}
		ap[pos] = true;
	}
	int cnt = 0;
	for (auto i : ap) if (!i) cnt++;
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
