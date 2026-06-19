#include <bits/stdc++.h>
using namespace std;
int T, a[100010][5], f[210][210][210], n;
struct node {
	int h, id;
} c[100010];
bool cmp(node a, node b) {
	return a.h < b.h;
}
void work1() {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		c[i].h = a[i][2] - a[i][1];
		c[i].id = i;
	}
	sort(c + 1, c + n + 1, cmp);
	for(int i = 1; i <= n / 2; i++) ans += a[c[i].id][1];
	for(int i = n / 2 + 1; i <= n; i++) ans += a[c[i].id][2];
	cout << ans << "\n";
}
void work2() {
	int ans = 0;
	f[0][0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= min(i, n / 2); j++) {
			for(int k = 0; k <= min(i - j, n / 2); k++) {
				if(i - j - k > n / 2) continue;
				if(i - j - k < 0) continue;
				f[i][j][k] = 0;
				if(j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
				if(k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
				if(i - j - k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
				ans = max(ans, f[i][j][k]);
			}
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][3]) flag = 1;
		}
		if(!flag) work1();
		else work2();
	}
	return 0;
}
