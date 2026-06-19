#include<bits/stdc++.h>
//#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
int n, a[N], cnt, viscnt = 1; bool  sur[N];
void solve() {
	cin >> n; rep(i, 1, n) cin >> a[i]; sort(a + 1, a + 1 + n);
	rep(i, 1, n) sur[i] = 1;
//	rep(i, 1, n) cout << a[i] << ' '; cout << '\n';
	rep(i, 1, n - 1) {
		int l = viscnt + 1, r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[mid] == a[i]) l = mid + 1;
			else if(a[mid] > a[i]) r = mid - 1;
//			if(i == 2) cout << l << ' ' << r << '\n';
		}
//		cout << i << ' ' << l << '\n';
		if(l <= n) sur[i] = 0, viscnt = l;
		else break; 
	}
	rep(i, 1, n) if(sur[i]) ++ cnt;
	cout << cnt;
}
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int T = 1; // cin >> T;
	while(T --) solve();
	return 0;
} 
