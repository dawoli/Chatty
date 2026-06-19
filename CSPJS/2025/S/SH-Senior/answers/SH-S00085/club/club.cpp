#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int t, n, a[N][4];
void bfdp() {
	vector<vector<vector<int> > > f(n+1, vector<vector<int> >(n/2+2, vector<int>(n/2+2)));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j*2 <= n && j <= i; j++) {
			for (int k = 0; k*2 <= n && k+j <= i; k++) {
				int l = i-j-k;
				if (j != 0)
					f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i][1]);
				if (k != 0)
					f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + a[i][2]);
				if (l != 0)
					f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + a[i][3]);
			}
		}
	}
	int ans = 0;
	for (int j = 0; j*2 <= n; j++) {
		for (int k = 0; k*2 <= n && k+j <= n; k++) {
			int l = n-j-k;
			if (l*2 > n) continue;
			ans = max(ans, f[n][j][k]);
		}
	}
	printf("%d\n", ans);
}
bool c12() {
	for (int i = 1; i <= n; i++)
		if (a[i][2] || a[i][3]) return false;
	return true;
}
void s12() {
	vector<int> reg;
	for (int i = 1; i <= n; i++)
		reg.push_back(a[i][1]);
	sort(reg.begin(), reg.end(), greater<int>());
	int ans = 0;
	for (int i = 1; i*2 <= n; i++)
		ans += reg[i-1];
	printf("%d\n", ans);
}
bool c13() {
	for (int i = 1; i <= n; i++)
		if (a[i][3]) return false;
	return true;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		if (n <= 200)
			bfdp();
		else if (c12())
			s12();
	}
	return 0;
}