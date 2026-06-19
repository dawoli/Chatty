#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,x,ans,a[100010][10],id[100010][10],ip[100010],c[10];
bool cmp(int u,int v){
	return a[x][u] > a[x][v];
}
void rep(int u){
	for(int i = 1;i <= n;i++){
		ip[i] = 0;
		if(id[i][1] == u) ip[i] = a[i][u] - a[i][id[i][2]];
	}
	sort(ip + 1,ip + n + 1);
	for(int i = 1;i <= n / 2;i++) ans -= ip[i];
}
void solve(){
	cin >> n;
	ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < 4;j++) cin >> a[x = i][id[i][j] = j];
		sort(id[i] + 1,id[i] + 4,cmp);
		c[id[i][1]]++;
		ans += a[i][id[i][1]];
	}
	for(int i = 1;i <= 3;i++){
		if(c[i] > n / 2) rep(i);
	}
	cout << ans << endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}
