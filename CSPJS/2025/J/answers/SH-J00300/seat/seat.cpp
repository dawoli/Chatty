#include <bits/stdc++.h>
using namespace std;

int score[105];
int seat[15][15];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	//100
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n*m; i++) cin >> score[i];
	int s = score[1];
	sort(score+1, score+n*m+1, cmp);
	int y = 1, st = 1, et = n;
	for (int i = 1; i <= n*m;) {
		if (y % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				seat[j][y] = score[i++];
				if (seat[j][y] == s) {
					cout << y << " " << j << endl;
				}
			}
		}
		else {
			for (int j = n; j >= 1; j--) {
				seat[j][y] = score[i++];
				
				if (seat[j][y] == s) {
					cout << y << " " << j << endl;
				}
			}
		}
		y ++;
	}
	return 0;
}
