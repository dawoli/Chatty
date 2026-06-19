#include<bits/stdc++.h>
using namespace std;
const int N=2e3+9;
typedef long long ll;
ll n,m,a[N],ans,tot;
ll f[N][N];
bool vis[N][N];
ll dfs(ll u,ll pre){
	if(vis[u][pre])return f[u][pre];
	if(u>n)return 0;
	return max(dfs(u+1,pre)+a[u]*(a[u]==a[u-1]),dfs(u+1,u-1)+a[u]*(a[u]==a[pre]));
}
void solve(){
	cin>>n;
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(1,0)<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
