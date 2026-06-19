#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n, a[500005], k, ans;
int s[500005];
bool A = 0, B = 0;
vector<pair<int, int> > g;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] ^ a[i];
		if (a[i] != 1) A = 1;
		if (a[i] != 1 && a[i] != 0) B = 1;
	}
	if (A == 0) {
		cout << n / 2;
		return 0;
	}
	if (B == 0) {
		for (int i = 1; i <= n; i++) 
			if (a[i] == k) ans++;
		cout << ans;
		return 0;
	}
	int st = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == k)
			g.push_back(make_pair(st, i - 1)), st = i + 1, ans++;
	}
	if (a[n] != k)
		g.push_back(make_pair(st, n));
	for (int i = 0; i < g.size(); i++) {
		int x = g[i].first, y = g[i].second;
		if (x >= y) continue; 
		for (int l = x; l <= y; l++) {
			for (int r = x + 1; r <= y; r++) {
				if ((s[r] ^ s[l - 1]) == k) {
					ans++;
					l = r + 1;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
