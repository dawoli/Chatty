#include <bits/stdc++.h>
using namespace std;
#define N 110
int n, m, A, a, cnt = 1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> A;
	for(int i = 1; i < n * m; i++) {
		cin >> a;
		cnt += (a > A);
	}
	int col = (cnt + n - 1) / n, row;
	cnt -= (col - 1) * n;
	if(col % 2 == 1) row = cnt;
	else row = n + 1 - cnt;
	cout << col << " " << row << endl;
	return 0;
}
