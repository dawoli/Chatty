#include<bits/stdc++.h>
using namespace std;

int t;
const int maxn = 1e6 + 7;
int a[maxn], c[maxn], n, cnt[maxn];
bool vis[maxn];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	cin >> t;
	while(t--){
		int ans=0;
		int maxnum = 0;
		cin >> n;
		memset(vis, false, sizeof(vis));
		for(int i = 1;i <= n; ++i){
			cnt[i] = 0, c[i] = 0;
		}
		for(int i =1;i<=n;++i){
			cin >> a[i];
		}
		for(int i =1; i<=n;++i){
			cnt[a[i]]++;
//			c[a[i]]+=a[i];
			if(!vis[a[i]]){
				vis[a[i]] = true;
				continue;
			}
			c[a[i]]+=a[i];
			if(a[i] == a[1])continue;
			maxnum=max(maxnum, c[a[i]]);
		}
		ans += (cnt[a[1]] - 1) * a[1];
		ans += maxnum;
		cout << ans;
		if(t)cout << '\n';
	}
	
	return 0;
}
