#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll P=998244353;
ll n,ans,mx,a[5009];
ll b[5009];
ll c(ll n,ll m){
	ll cnt=1;
	for(ll i=n;i>=n-m+1;i--) cnt*=i;
	for(ll i=m;i>=1;i--) cnt/=i;
	return cnt%P;
}
void dfs(ll i,ll j,ll sum,ll mx){
	if(i==n+1){
		if(sum>2*mx&&j>=3)
			ans++;
		return;
	}
	b[i]=1;
	dfs(i+1,j+1,sum+a[i],max(mx,a[i]));
	b[i]=0;
	dfs(i+1,j,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	/*if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}else */if(mx==1){
		ll cnt=0;
		for(ll i=2;i<=n-1;i++)
			for(ll j=2;j<=i;j++)
				 cnt=(cnt+c(i,j))%P;
		cout<<cnt%P;
	}
	return 0;
}
