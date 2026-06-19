#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,vis[1010],b[1010];
char a[1010];
int dfs(int d,int l,int w){
	if(d==n+1&&w>=m)return 1;
	if(d==n+1)return 0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[d]=='1'&&l<b[i])ans+=dfs(d+1,l,w+1);
			else ans=(ans+dfs(d+1,l+1,w))%998244353;
			vis[i]=0;
		} 
	}
	return ans;
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cout<<dfs(1,0,0)<<endl;
	return 0;
} 
