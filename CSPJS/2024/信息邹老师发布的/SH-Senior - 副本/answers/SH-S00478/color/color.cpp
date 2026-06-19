#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],c[N];
int n;
int ans=-1;
void dfs(int t,int sum,int red,int blue){
	if(t>n){
		ans=max(ans,sum);
		return;
	}
	c[t]=0;
	if(a[t]==red)dfs(t+1,sum+a[t],a[t],blue);
	else dfs(t+1,sum,a[t],blue);
	c[t]=1;
	if(a[t]==blue)dfs(t+1,sum+a[t],red,a[t]);
	else dfs(t+1,sum,red,a[t]);
	return;
}
void solve(){
	ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,-1,-1);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
