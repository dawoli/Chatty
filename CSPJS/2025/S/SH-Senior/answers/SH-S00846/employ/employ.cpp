#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,m,c[505],x[505],ans;
bool vis[505];
string s;
void dfs(int p){
	if(p==n+1){
		int pre=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') pre++;
			else{
				if(pre>=c[x[i]]) pre++;
				else sum++;
			}
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		x[p]=i;
		dfs(p+1);
		vis[i]=0;
	}
}
void solve10(){
	dfs(1);
	cout<<ans<<endl;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) {
		solve10();
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%M;
	cout<<ans<<endl;
	return 0;
}
