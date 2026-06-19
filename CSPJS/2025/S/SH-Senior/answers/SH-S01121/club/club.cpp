#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, n, ans, b[4], vis[N], s[N][3];

struct node {
	int val, i, j;
}a[3*N], c[N];

int fr() {
	int x = 0, w = 1;char c = getchar();
	while(c < '0' || c > '9'){if(c == '-'){w = -1;} c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0'; c = getchar();}
	return x * w;
}

bool cmp(node u, node v) {
	return u.val > v.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = fr();
	while(t--) {
		memset(b, 0, sizeof b);
		memset(a, 0, sizeof a);
		memset(vis, 0, sizeof vis);
		ans = 0;
		n = fr();
		for(int i = 0, u;i < n;i++) {
			for(int j = 1;j <= 3;j++) {
				cin >> s[i + 1][j];
				a[i * 3 + j].val = s[i + 1][j];
				a[i * 3 + j].i = i + 1;
				a[i * 3 + j].j = j;
			}
		}
		sort(a + 1, a + 3 * n + 1, cmp);
		int cnt = 0;
		int j = 0;
		for(int i = 1;i <= 3 * n;i++) {
			if(vis[a[i].i] || b[a[i].j] >= (n/2)) continue;
			ans += a[i].val;
			b[a[i].j]++;
			vis[a[i].i] = a[i].j;
			cnt++;
			if(b[a[i].j] == (n/2) && !j) j = a[i].j;
			if(cnt >= n) break;
		}
//		cout << j << endl;
		if(j) {
			for(int i = 1;i <= n;i++) {
				if(vis[i] == j) {
					if(j == 1) {
						c[i].val = s[i][1] - max(s[i][2], s[i][3]);
						c[i].i = i;
						c[i].j = j; 
					}
					else if(j == 2) {
						c[i].val = s[i][2] - max(s[i][1], s[i][3]);
						c[i].i = i;
						c[i].j = j; 
					}
					else if(j == 3) {
						c[i].val = s[i][3] - max(s[i][1], s[i][2]);
						c[i].i = i;
						c[i].j = j;
					}
				}
				else {
					c[i].val = s[i][j] - s[i][vis[i]];
					if(c[i].val < 0) c[i].val -= 1e9;
					c[i].i = i;
					c[i].j = vis[i]; 
				}
			}
			sort(c + 1, c + n + 1, cmp);
			for(int i = 1;i <= n;i++) {
//				cout << c[i].val << ' ' << c[i].i << ' ' << c[i].j << endl;
				if(i <= (n/2)) {
					if(c[i].j != j) ans += c[i].val;
				}
				else {
					if(c[i].j == j) ans -= c[i].val;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
