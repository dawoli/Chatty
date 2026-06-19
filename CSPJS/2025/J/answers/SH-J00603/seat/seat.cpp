#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], r = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			if (a[i][j] > a[1][1])
				r++;
		}
	cout << (r - 1) / n + 1 << ' ';
	int t = r % (2 * n);
	if (t <= n) cout << t;
	else cout << 2 * n - t + 1;
	return 0; 
} 
