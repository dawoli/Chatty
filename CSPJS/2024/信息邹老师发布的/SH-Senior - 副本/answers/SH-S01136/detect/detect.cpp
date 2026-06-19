#include<bits/stdc++.h> 
#define int long long
using namespace std;
int TTT;
const int N = 1e6 + 10;
int p[N];

int d[N];
int v[N];
int a[N];
int x;
int n,m,l,V;
signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> TTT;
	while(TTT--) {
		cin >> n >> m >> l >> V;
		for (int i = 1; i <= n; i++) {
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1; i <= m; i++ ) {
			cin >> p[i];
		}
		int ans1 = 0;
		for (int i = 1; i <= n; i++) {
			if(v[i] > V && d[i] <= p[m]) {
				++ans1;
			}
		}
		int ans2 = 0;
		if(ans1 == 0) {
			ans2 = m;
		}else {
			ans2 = m - 1;
		}
		cout << ans1 << " " << ans2 << endl;
	} 
	return 0;
}
