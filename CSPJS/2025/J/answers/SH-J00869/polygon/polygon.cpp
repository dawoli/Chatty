#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int n;
int a[500005];
int ans=0;
void dfs(int step,int s,int sum,int maxn){
	if(step>=3&&step<=n+1){
		if(sum>2*maxn)
		{
			ans++;
		}
	}
	if(step==n+1)return ;
	for(int i=s+1;i<=n;i++){
		dfs(step+1,i,sum+a[i],max(maxn,a[i]));
	}
}
int qpow(int a,int b){
	int res=1,base=a;
	while(b){
		if(b&1)res=res*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag)
	{
		cout<<qpow(2,n)-n*(n-1)/2-n-1;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0; 
}
