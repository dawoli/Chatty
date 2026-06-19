#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll N=5009;
ll n;
ll a[N];
ll C[N];
ll p[29];
bool ok1=1;
void preC(){
	ll res=1;
	C[0]=1;
	C[n]=1;
	for(int i=1;i<n;i++){
		res*=(n-i+1);
		res/=i;
		C[i]=res%MOD;
	}
}
void work1(){
	preC();
	ll ans=0;
	for(ll i=3;i<=n;i++){
		ans+=C[i];
		ans%=MOD;
	}
	printf("%lld",ans);
}
ll ans=0;
void dfs(ll dep){
	if(dep==n+1){
		ll sum=0,mx=0;
		for(ll i=1;i<=n;i++){
			sum+=(p[i]?a[i]:0);
			mx=max(mx,(p[i]?a[i]:0));
		}
		if(sum>mx*2){
			ans++;
			ans%=MOD;
		}
		return;
	}
	p[dep]=1;
	dfs(dep+1);
	p[dep]=0;
	dfs(dep+1);
	p[dep]=-1;
}
void workn20(){
	for(ll i=1;i<=n;i++){
		p[i]=-1;
	}
	dfs(1);
	printf("%lld",ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1){
			ok1=0;
		}
	}
	if(n<=20){
		workn20();
		return 0;
	}
	if(ok1){
		work1();
		return 0;
	}
	return 0;
}
