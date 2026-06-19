#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,s[N],c[N],vis[N],a[N],ans;
char ch;
void dfs(int x){
	if(x>n){
		int cnt=0,tmp=0;
		for(int i=1;i<=n;++i){
			if(s[i]==0){
				tmp++;
				continue;
			}
			if(tmp<c[a[i]]) cnt++;
			else tmp++;
		}
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		vis[i]=0;
		a[x]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
