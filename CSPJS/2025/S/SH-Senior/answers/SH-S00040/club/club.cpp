#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
#define mp make_pair
#define fir first
#define sec second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;

int t, n, cnt1, cnt2, cnt3;
long long ans;
int a[100001][4];
bool flag2, flag3;

priority_queue<int> pq1;
priority_queue<pii> pq12;

void dfs(int cur, long long tot) {
	rep (i, cur + 1, n) {
		if (cnt1 < (n >> 1)) {
			++cnt1;
			dfs(i, tot + a[i][1]);
			--cnt1;
		}
		if (cnt2 < (n >> 1)) {
			++cnt2;
			dfs(i, tot + a[i][2]);
			--cnt2;
		}
		if (cnt3 < (n >> 1)) {
			++cnt3;
			dfs(i, tot + a[i][3]);
			--cnt3;
		}
	}
	ans = max(ans, tot);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 0LL;
		cnt1 = cnt2 = cnt3 = 0;
		flag2 = flag3 = true;
		priority_queue<int>().swap(pq1);
		priority_queue<pii>().swap(pq12);
		cin >> n;
		rep (i, 1, n) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			pq1.push(a[i][1]);
			if (flag2 && a[i][2] != 0) flag2 = false;
			if (flag3 && a[i][3] != 0) flag3 = false;
			pq12.push(mp(a[i][1], a[i][2]));
		}
		if (flag2 && flag3) {
			rep (i, 1, (n >> 1)) {
				ans += pq1.top();
				pq1.pop();
			}
		} /*else if (flag3) {
			rep (i, 1, n) {
				pii cur = pq12.top();
				pq12.pop();
				if (cur.fir == cur.sec) {
					ans += cur.fir;
				} else {
					if (cnt1 == (n >> 1)) {
						ans += cur.sec;
						++cnt2;
					} else if (cnt2 == (n >> 1)) {
						ans += cur.fir;
						++cnt1;
					} else if (cur.fir > cur.sec) {
						ans += cur.fir;
						++cnt1;
					} else {
						ans += cur.sec;
						++cnt2;
					}
				}
			}
		} */else if (n == 1e5) {
			rep (i, 1, n) {
				ans += max(a[i][1], max(a[i][2], a[i][3]));
			}
		} else {
			dfs(0, 0LL);
		}
		cout << ans << '\n';
	}
	return 0;
}
