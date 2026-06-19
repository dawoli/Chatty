#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define ld long double
#define int128 __int128
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define ROF(i,n,m) for(int i=(n);i>=(m);i--)
#define REP(i,n) for(int i=0;i<(n);i++) 
#define SZ(v) v.size()
#define PII pair<int, int>
#define FI(v) v.first
#define SE(v) v.second
#define BG(v) v.begin()
#define ED(v) v.end()
#define ALL(V) BG(v), ED(v)
#define endl '\n'
template < typename A , typename B >
inline bool chmax(A &x, B y) { return (x < y ? (x = y, true) : false); }
template < typename A , typename B >
inline bool chmin(A &x, B y) { return (x > y ? (x = y, true) : false); }
const int N = 1e5 + 5;
int n, a[N];
void solve() {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = n, res = 0, cnt = 0;
	FOR(i, 1, n) {
		if(a[i] != a[i - 1]) {
			res += cnt;
			cnt = 0;
		}
		if(res) res -- , ans --;
		cnt ++;
	}
	cout << ans << endl;
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
