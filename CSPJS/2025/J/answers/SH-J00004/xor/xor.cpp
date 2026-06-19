#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N], pre[N], n, k, vis[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	int cnt = 0, ans = 0; 
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			if(n - cnt < r - l) continue;
			if((pre[r] ^ pre[l - 1]) != k) continue;
			bool flag = 0;
			for(int j = l; j <= r; j++) {
				if(vis[j]){
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			ans++, cnt -= r - l + 1;
			for(int j = l; j <= r; j++) {
				vis[j] = 1;
			};
			break;
		}
	}
	cout << ans ;
	return 0;
}
