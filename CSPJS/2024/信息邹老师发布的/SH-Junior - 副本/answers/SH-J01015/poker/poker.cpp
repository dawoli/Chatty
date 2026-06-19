#include <iostream>
#include <cstdio>
using namespace std;

int n, ans = 0;
bool box[10][20];
int color_num[256], number_num[256];

void init() {
	for (int i = 2; i <= 9; i++)
		number_num[i + '0'] = i;
	number_num['A'] = 1;
	number_num['T'] = 10;
	number_num['J'] = 11;
	number_num['Q'] = 12;
	number_num['K'] = 13;

	color_num['D'] = 1;
	color_num['C'] = 2;
	color_num['H'] = 3;
	color_num['S'] = 4;
}

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c1, c2;
		cin >> c1 >> c2;
		box[color_num[c1]][number_num[c2]] = true;
	}

	for (int i = 1; i <= 4; i++) 
		for (int j = 1; j <= 13; j++)
			if (!box[i][j])
				ans++;

	cout << ans << endl;
	return 0;
}