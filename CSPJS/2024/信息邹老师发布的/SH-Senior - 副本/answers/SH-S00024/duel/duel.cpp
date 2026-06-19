#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 100005
#define R 100005

int n;
int a[N];
int cnt[R];
int ans;

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] > ans) {
			ans = cnt[a[i]];
		}
	}
	cout << ans << endl;
}
