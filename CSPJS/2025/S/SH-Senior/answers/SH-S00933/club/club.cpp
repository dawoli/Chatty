#include <bits/stdc++.h>
//#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 100005;
const int INF = 0x3f3f3f3f;
struct stu { 
	int val, id; 
	friend bool operator < (stu x, stu y) {
		return x.val > y.val;
	}
};
int n, sum, dm = -INF;
bool vis[N];
stu a[N], b[N], c[N];
void clear() {
	rep(i, 1, n) a[i].val = a[i].id = b[i].val = b[i].id = c[i].val = c[i].id = 0;
	rep(i, 1, n) vis[i] = 0;
	n = sum = 0;
}
void solve() {
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i].val >> b[i].val >> c[i].val;
		dm = max(max(a[i].val, b[i].val), c[i].val);
		a[i].id = b[i].id = c[i].id = i;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	sort(c + 1, c + 1 + n);
	int cntt[4]; cntt[1] = cntt[2] = cntt[3] = 1;
	int uu[4]; uu[1] = uu[2] = uu[3] = 1; 
	per(d, dm, 0) {
		if( (a[cntt[1]].val == d && uu[1] && !vis[a[cntt[1]].id]) || (b[cntt[2]].val == d && uu[2] && !vis[b[cntt[2]].id]) || (c[cntt[3]].val && uu[3] && !vis[c[cntt[3]].id]) ) {
			int cnt = 0, pos[4]; memset(pos, 0, sizeof(pos));
			if((a[cntt[1]].val == d) && uu[1] && !vis[a[cntt[1]].id]) ++ cnt, pos[1] = 1;
			if((b[cntt[2]].val == d) && uu[2] && !vis[b[cntt[2]].id]) ++ cnt, pos[2] = 1;
			if((c[cntt[3]].val == d) && uu[3] && !vis[c[cntt[3]].id]) ++ cnt, pos[3] = 1;
			if(cnt == 1) {
				int u = 0;
				rep(i, 1, 3) if(pos[i] == 1) { u = i; break; }
				cout << d << ":" << u << '\n';
				if(u == 1) sum += a[cntt[1]].val;
				else if(u == 2) sum += b[cntt[2]].val;
				else if(u == 3) sum += c[cntt[3]].val;
				if(u == 1) vis[a[cntt[1] ++].id] = 1;
				else if(u == 2) vis[b[cntt[2] ++].id] = 1;
				else if(u == 3) vis[c[cntt[3] ++].id] = 1;
			} else if(cnt == 2) {
				int u = 0;
				rep(i, 1, 3) if(pos[i] == 0) { u = i; break; }
				if(u == 1) {
					int minn = min(cntt[2], cntt[3]);
					if(minn = cntt[2] && !vis[b[cntt[2]].id]) {
						sum += b[cntt[2]].val, vis[b[cntt[2] ++].id] = 1;
						if(cntt[2] > n / 2) uu[2] = 0;	
					}
					if(minn = cntt[3] && !vis[c[cntt[3]].id]) {
						sum += c[cntt[3]].val, vis[c[cntt[3] ++].id] = 1;
						if(cntt[3] > n / 2) uu[3] = 0;
					}
				} else if(u == 2) {
					int minn = min(cntt[1], cntt[3]);
					if(minn = cntt[1] && !vis[a[cntt[1]].id]) {
						sum += a[cntt[1]].val, vis[a[cntt[1] ++].id] = 1;
						if(cntt[1] > n / 2) uu[1] = 0;
					}
					if(minn = cntt[3] && !vis[c[cntt[3]].id]) {
						sum += c[cntt[3]].val, vis[c[cntt[3] ++].id] = 1;
						if(cntt[3] > n / 2) uu[3] = 0;
					}
				} else {
					int minn = min(cntt[1], cntt[2]);
					if(minn = cntt[1] && !vis[a[cntt[1]].id]) {
						sum += a[cntt[1]].val, vis[a[cntt[1] ++].id] = 1;
						if(cntt[1] > n / 2) uu[1] = 0;
					}
					if(minn = cntt[2] && !vis[b[cntt[2]].id]) {
						sum += b[cntt[2]].val, vis[b[cntt[2] ++].id] = 1;
						if(cntt[2] > n / 2) uu[2] = 0;
					}
				}
			} else {
				int minn = min(min(cntt[1], cntt[2]), cntt[3]);
				if(minn = cntt[1] && !vis[a[cntt[1]].id]) {
					sum += a[cntt[1]].val, vis[a[cntt[1] ++].id] = 1;
					if(cntt[1] > n / 2) uu[1] = 0;
				}
				if(minn = cntt[2] && !vis[b[cntt[2]].id]) {
					sum += b[cntt[2]].val, vis[b[cntt[2] ++].id] = 1;
					if(cntt[2] > n / 2) uu[2] = 0;
				}
				if(minn = cntt[3] && !vis[c[cntt[3]].id]) {
					sum += c[cntt[3]].val, vis[c[cntt[3] ++].id] = 1;
					if(cntt[3] > n / 2) uu[3] = 0;
				}
			}
		}
	}
	cout << sum << '\n';
	return;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) clear(), solve();
	return 0;
}
