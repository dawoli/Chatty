#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
long long ans=1;
int a[505];
bool vis[505];
void dfs(int k,int x,int cnt,int cnt2){
	if(cnt>=m){
		ans++;
		ans%=mod;
		return;
	}
	if(k==n) return;
	for(int i=1;i<=n;i++){
		vis[x]=1;
		if(vis[i]) continue;
		if(a[i]<cnt2||s[k]=='0') dfs(k+1,i,cnt,cnt2+1);
		else dfs(k+1,i,cnt+1,cnt2);
		vis[x]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 
