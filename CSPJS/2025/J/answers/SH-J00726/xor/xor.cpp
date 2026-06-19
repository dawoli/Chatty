#include<bits/stdc++.h> 
using namespace std;
int n, k, a[500010]; long long vis[500010];
long long ans;
inline int getk(int l, int r) {
	return a[r] ^ a[l - 1];
}
void dfs(int now, long long cn) {
 	vis[now] = max(vis[now], cn);

	for(int r = now; r <= n; r++) {
		for(int l = now; l <= r; l++) {
			if(getk(l, r) == k && vis[r + 1] < cn + 1) {
				dfs(r + 1, cn + 1); 
				return;
			} 
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin >> n >> k >> a[1];
	for(int i = 2, inp; i <= n; i++) {
		cin >> inp;
		a[i] = a[i - 1] ^ inp;
	}
	dfs(1, 0);
	for(int i = 0; i <= n + 1; i++) ans = max(ans, vis[i]);
	cout << ans;
	return 0;
}
