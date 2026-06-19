#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100010],ans,p[5050][5050];
void dfs(ll l,ll d,ll maxn,ll sum){
	if(l==n){
		if(d>=3&&sum>maxn*2)ans++;
		return;
	}
	dfs(l+1,d+1,max(maxn,a[l+1]),sum+a[l+1]);
	dfs(l+1,d,maxn,sum);
}
ll f(ll x){
	ll y=0,sum=1;
	for(int i=1;i<=n;i++){
		y=0;
		for(int j=1;j<=n;j++)y+=p[j][i];
		for(int j=1;j<=x;j++)y-=p[j][i];
		for(int j=1;j<=n-x;j++)y-=p[j][i];
		while(y--){
			sum*=i;
			sum%=998244353;
		}
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=26){
		dfs(0,0,0,0);
		printf("%lld",ans);
		return 0;
	}
	for(int i=2;i<=n;i++){
		ll x=i;
		for(int j=2;j<=x;j++){
			while(x%j==0&&x){
				p[i][j]++;
				x/=j;
			}
		}
	}
	for(int i=3;i<=n;i++){
		ans+=f(i);
		ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}
