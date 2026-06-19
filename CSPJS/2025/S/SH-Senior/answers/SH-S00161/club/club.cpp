#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
namespace IANYEYZ {
	struct people {
		int a[4], b, c;
		bool operator<(const people rhs) const {
			return b - c > rhs.b - rhs.c;
		}
	}p[100010];
	int n, t;
	struct Ne {
		int b, c, id;
		bool operator<(const Ne rhs) const {
			return (max(b, c) == max(rhs.b, rhs.c) ? id < rhs.id : max(b, c) > max(rhs.b, rhs.c));
		}
	}ne[100010];
	int vis[100010], ch[100010];
	vector<pair<int, int> > c;
	void chkmin(int &res, int v) { res = min(res, v); }
	void chkmax(int &res, int v) { res = max(res, v); }
	int find(int v, int id) {
		int l = 0, r = c.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (c[mid] == (pair<int, int>){v, id}) return mid;
			if (c[mid] < (pair<int, int>){v, id}) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return -1;
	}
	int calc1(int cnt, int k1, int k2, int y) {
		rep (i, 0, cnt) vis[i] = 0;
		int res = 0, mmax = 0;
		sort(ne + 1, ne + cnt + 1);
		vector<int> v;
		rep (i, 1, cnt) {
			v.push_back(max(ne[i].b, ne[i].c));
		}
		sort(v.begin(), v.end());
//		for (auto i:v) {
//			cout << i << " ";
//		}
//		cout << "\n";
		rep (i, v.size() - y, v.size() - 1) {
			mmax += v[i];
		}
//		cout << mmax << "\n";
		return mmax;
	}
	int calc() {
		cin >> n;
		rep (i, 1, n) {
			rep (j, 1, 3) {
				cin >> p[i].a[j];
			}
		}
		int ans = 0;
		// 先随便选
		int cnt[4] = {};
		rep (i, 1, n) {
			int mmax = -1, flag = 0;
			rep (j, 1, 3) {
				if (p[i].a[j] > mmax) {
					mmax = p[i].a[j]; flag = j;
				}
			}
			ans += mmax;
			ch[i] = flag;
			cnt[flag]++;
		}
		int flag = 0;
		rep (i, 1, 3) {
//			cout << cnt[i] << "\n";
			if (cnt[i] > n / 2) flag = i;
		}
		if (flag == 0) {
			// 没有超过的，直接返回
			return ans;
		} else {
			int c[3] = {};
			c[1] = ((flag != 1) ? 1 : 2); c[2] = ((flag == 3) ? 2 : 3);
			int tot = 0;
//			cout << flag << "\n";
//			cout << c[1] << " " << c[2] << "\n";
			rep (i, 1, n) {
				if (ch[i] == flag) {
					ne[++tot].b = p[i].a[c[1]] - p[i].a[flag];
					ne[tot].c = p[i].a[c[2]] - p[i].a[flag];
					ne[tot].id = tot;
//					cout << p[i].a[c[1]] << " " << p[i].a[c[2]] << "\n";
//					cout << i << " " << ne[tot].b << " " << ne[tot].c << "\n";
				}
			}
			// 问题变为，给定两个序列 b, c，第一个序列至多取 k1 个，第二个序列至多取 k2 个，总共取 y 个，求最大值
			return ans + calc1(tot, n / 2 - cnt[c[1]], n / 2 - cnt[c[2]], tot - n / 2);
//			return (n / 2 - cnt[c[1]] >= tot - n / 2) && (n / 2 - cnt[c[2]] >= tot - n / 2);
		}
	}
	void solve() {
		cin >> t;
		while (t--) {
			cout << calc() << "\n";
		}
	}
}
int main() {
	cin.tie(0) -> ios :: sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	IANYEYZ :: solve();
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
