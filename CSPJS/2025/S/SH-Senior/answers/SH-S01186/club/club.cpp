#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, ans, a[N], b[N], c[N];
int dp[201][201][201];
bool flag[201][201][201], A, B;

struct node {
	int del, id;
	bool operator< (const node x) const {
		return del > x.del;
	}	
};
priority_queue<node> ra, rb, rc;
int cnt[4];

int dfs(int i, int cnt1, int cnt2) {
	int cnt3 = i - cnt1 - cnt2 - 1;
	if(cnt1 * 2 > n || cnt2 * 2 > n || cnt3 * 2 > n) return -1e9;
	if(i == n + 1) return 0;
	if(flag[i][cnt1][cnt2]) return dp[i][cnt1][cnt2];
	//cout << i << " " << cnt1 << " " << cnt2 << endl;
	int res = max({dfs(i + 1, cnt1 + 1, cnt2) + a[i], dfs(i + 1, cnt1, cnt2 + 1) + b[i], dfs(i + 1, cnt1, cnt2) + c[i]});
	flag[i][cnt1][cnt2] = 1;
	return dp[i][cnt1][cnt2] = res;
}

int dfs2(int i, int cnt1) {
	int cnt2 = i - cnt1 - 1;
	if(cnt1 * 2 > n || cnt2 * 2 > n) return -1e9;
	if(i == n + 1) return 0;
	if(flag[i][1][cnt1]) return dp[i][0][cnt1];
	//cout << i << " " << cnt1 << " " << cnt2 << endl;
	int res = max({dfs2(i + 1, cnt1 + 1) + a[i], dfs2(i + 1, cnt1) + b[i]});
	flag[i][1][cnt1] = 1;
	return dp[i][1][cnt1] = res;
}

void solve() {
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int t = max({a[i], b[i], c[i]});
		res += t; 
		if(t == a[i]) {
			ra.push({t - max(b[i], c[i]), b[i] > c[i] ? 2 : 3});
			cnt[1]++;
			if(cnt[1] > n / 2) {
				cnt[1]--;
				node top = ra.top();
				ra.pop();
				res -= top.del;
				cnt[top.id]++; 
			}

		}
		else 
		if(t == b[i]) {
			rb.push({t - max(a[i], c[i]), a[i] > c[i] ? 1 : 3});
			cnt[2]++;
			if(cnt[2] > n / 2) {
				cnt[2]--;
				node top = rb.top();
				rb.pop();
				res -= top.del;
				cnt[top.id]++; 
			}
		}
		
		else {
			rc.push({t - max(b[i], a[i]), b[i] > a[i] ? 2 : 1});
			cnt[3]++;
			if(cnt[3] > n / 2) {
				cnt[3]--;
				node top = rc.top();
				rc.pop();
				res -= top.del;
				cnt[top.id]++; 
			}

		}
	}
	cout << res << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        memset(flag, 0, sizeof flag);
        for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			if(b[i] || c[i]) A = 0;
			if(c[i]) B = 0;
		}
		while(!ra.empty()) ra.pop();
		while(!rb.empty()) rb.pop();
		while(!rc.empty()) rc.pop();
		cnt[1] = cnt[2] = cnt[3] =0;
		solve();
        //else cout << dfs(1, 0, 0) << endl;
    }
}
