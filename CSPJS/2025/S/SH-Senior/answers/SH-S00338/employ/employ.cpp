#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[510];
int ans=0;
int a[510];
int vis[510];
void dfs(int step,int qt){
	if(n-qt<m)return;
	if(step==n+1){
		if(n-qt>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(s[step]=='1'&&c[i]>qt)dfs(step+1,qt);
		else dfs(step+1,qt+1);
		vis[i]=0;
	}
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	bool all1=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			all1=0;
			break;
		} 
	}
	bool no0=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)no0=0;
	}
	if(m==n){
		if(no0==0||all1==0){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
