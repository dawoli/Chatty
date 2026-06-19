#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n, a[maxn];
int vis[maxn];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w",stdout);
	cin >> n;
	int maxn = 0x80808080;
	int minn = 2147483646;
	int smin = 2147483647;
	int mina = 0, smia = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		maxn = max(a[i], maxn);
		minn = min(a[i], minn);
		if (minn < a[i]) {
			smin = min(a[i], smin);
		}
	}
//	cout << smin << " " << minn << " ";
	int ans = n;
	bool flag = false;
	while (!flag) {
		bool falg = false;
		for (int i = 1; i <= n; i++) {
			if (vis[i]!=0) continue;
			if (a[i] != smin) continue;
//			cout << 3;
			for (int j = 1; j <= n; j++) {
				if (a[j] != minn || vis[j] == 2) continue;
//				cout << 4;
				if (a[i] > a[j]) {
					ans--;
					vis[j] = 2;
					vis[i] = 1;
//					cout << i << " -> " << j << "\n";
					falg = true;
					break;
				}
			}
		}
		if (falg == false) {
			break;
		}
//		cout << vis[3];
		minn = 2147483646;
	    smin = 2147483647;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 2) continue;
			minn = min(a[i], minn);
			if (a[i] > minn) {
				smin = min(a[i], smin);
			}
		}
//		cout << smin << " " << minn << " ";
	}
	cout << ans;
	return 0;
}
