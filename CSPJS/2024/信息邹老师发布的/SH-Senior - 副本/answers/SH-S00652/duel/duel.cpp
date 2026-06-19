#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

namespace August_Light {
	int n;
	int a[MAXN];
	int c[MAXN];
	int V = 1e5;
	void Main() {
		cin >> n;
		rep(i, 1, n)
			cin >> a[i], c[a[i]]++;
		
		int cur = 0, ans = 0;
		rep(i, 1, V) {
			if (cur <= c[i])
				ans += cur, cur = 0;
			else
				ans += c[i], cur -= c[i];
			cur += c[i];
			//cerr << cur << " " << ans << '\n';
		}
		cout << n - ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	August_Light::Main();
	return 0;
}
