#include<bits/stdc++.h> 
#define int long long
using std::cin;
using std::cout;
using std::endl;
const int N = 1e5 + 5;
int a[N];
int c[N];
int lg[N];
int k;
int d[100][100];
char s[100];
int n,m;
int T;
int x[10];
int ans;
int re[N];
int sum;
int vis[N];
signed main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	k = lg[n] + 1;
	for (int i = 1; i <= k; i++) {
		scanf("%s",s + 1);
		for (int j = 1; j <= (1 << (k - i)); j++) {
			d[i][j] = s[j] - '0';
		}
	}
	cin >> T;
	while(T--) {
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i = 1; i <= n; i++) {
			a[i] = a[i] ^ x[i % 4];
		}
		ans = 0;
		for (int i = 0; i <= n + 3; i++) {
			re[i] = 0;
			re[1] = 1; 
			ans = (ans ^ (i * sum));
		}
		cout << ans << endl;
	}
	return 0;
}
