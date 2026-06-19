#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int p[503],c[503],n,m,res;
int vis[503];
string s;
void solve(){
	int cnt=0,sum=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt++;
		if(s[i]=='1'){
			if(c[p[i+1]]<=cnt) cnt++;
			else sum++;
		}
	}if(sum>=m) res=(res+1)%MOD;
}
void dfs(int x){
	if(x==n+1){solve();return;}
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<res<<endl;
	return 0;
}
