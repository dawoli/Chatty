#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll MOD=998244353;
ll a[N],ans=0,n;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}
void dfs(ll x,ll cnt,ll mx,ll k){
	if(x==n+1){
		if(cnt>2*mx&&k>=3) ans++;
		return;
	}
	dfs(x+1,cnt+a[x],max(mx,a[x]),k+1);
	dfs(x+1,cnt,mx,k);
}
bool isCondition(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
void solveCondition(){
	cout<<((qpow(2,n)-1-n-(n*(n-1)%MOD*499122177ll%MOD))%MOD+MOD)%MOD<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	else if(isCondition()) solveCondition();
	return 0;
}
