#include <bits/stdc++.h> 
using namespace std;
int buc[14][5];
pair<int, int> numb(string s) {
	pair<int, int> ret;
	switch(s[1]) {
		case 'A':
			ret.first = 1;
			break;
		case 'T':
			ret.first = 10;
			break;
		case 'J':
			ret.first = 11;
			break;
		case 'Q':
			ret.first = 12;
			break;
		case 'K':
			ret.first = 13;
			break;
		default:
			ret.first = s[1] - '0';
			break;
	}
	switch(s[0]) {
		case 'D':
			ret.second = 1;
			break;
		case 'C':
			ret.second = 2;
			break;
		case 'H':
			ret.second = 3;
			break;
		case 'S':
			ret.second = 4;
			break;
		default:
			break;
	}
	return ret;
}
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		pair<int, int> p = numb(s);
		buc[p.first][p.second]++;
	}
	int res = 52;
	for (int i = 1; i <=13; i++) {
		for (int j = 1; j <= 4; j++) {
			if (buc[i][j] > 0) {
				res--;
			}
		}
	}
	cout << res;
	return 0;
}
