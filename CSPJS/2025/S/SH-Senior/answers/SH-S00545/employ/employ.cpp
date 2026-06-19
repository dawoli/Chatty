#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],vis[510],un,ans;
char s[510];
void dfs(int dep){
	if(dep==n+1){
		if(n-un>=m) ++ans;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(un>=c[i]||s[dep]=='0') un++;
			dfs(dep+1);
			if(un>=c[i]||s[dep]=='0') un--;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
