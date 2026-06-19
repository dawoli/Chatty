#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,a[5001];
ll ans=0;
ll dfs(int u,int sum,int mx,int cnt){
	sum+=a[u];
	mx=max(mx,a[u]*2);
	if(cnt>=3&&sum<=mx){
		return 0;
	}
	ll d=0;
	int cn=0;
	for(int i=u+1;i<=n;++i){
		int t=dfs(i,sum,mx,cnt+1);
		if(cnt<3&&((cnt+t)>=3)){
			cn++;
		}
		d=(d+t%mod)%mod;
	}
	if(cnt<3){
		return d+(cn>=1);
	}
	return d+1;
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;++i){
		ans=(ans+dfs(i,0,0,1)%mod)%mod;
	}
	cout<<ans;
	return 0;
}
