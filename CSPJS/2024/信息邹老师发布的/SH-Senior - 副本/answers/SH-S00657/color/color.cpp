#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll T,n,ans,a[N],c[N];
ll solve(){
	ll sum=0;
	for(ll i=n;i>1;--i)for(ll j=i-1;j>0;--j)if(c[i]==c[j]){
		sum+=(a[i]==a[j]?a[i]:0);
		break;
	}return sum;
}
void dfs(ll depth){
	if(depth>n){ans=max(ans,solve());return;}
	c[depth]=0,dfs(depth+1),c[depth]=1,dfs(depth+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
		ans=0,dfs(1),printf("%lld\n",ans);
	}
	return 0;
}
