#include <bits/stdc++.h>
#define rep(x, y, z) for (int x=(y); x<=(z); x++)
#define debug(x) cout << (#x) << "=" << (x) << endl;
#define line cout << endl;

using namespace std;

const int N = 1e5+5;
int n, r[N], f[N], die[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 0, n-1) {
		cin >> r[i];
	}

	sort(r, r+n);

	f[0] = 0;
	rep(i, 1, n-1) {
		if (r[i]!=r[i-1]) f[i] = i;
		else f[i] = f[i-1];
	}
	
	for (int i=n-1; i>=0; i--) {
		for (int j=f[i]-1; j>=0; j--) {
			if(!die[j]) {
				die[j] = 1;
				break;
			}
		}
	}

	int cnt=0;
	rep(i, 0, n-1) {
		if (!die[i]) cnt++;
	}
	cout << cnt << endl;

	return 0;
}
