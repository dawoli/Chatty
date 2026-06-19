#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=100010;
ll T,n,m,k,nk;
ll vx[4];
ll a[MaxN];
ll q[MaxN];
ll va[MaxN];
ll dp[MaxN];
ll ans[MaxN];
char b[20][MaxN];
int main(){
	ll rx;
	//*/
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	//*/
	scanf("%lld%lld",&n,&m);
	k=log2(n-1)+1;
	for(ll i=1;i<=n;i++)
		scanf("%lld",va+i);
	for(ll i=1;i<=m;i++)
		scanf("%lld",q+i);
	for(ll i=1;i<=k;i++)
		scanf("%s",b[i]+1);
	scanf("%lld",&T);
	while(T-->0){
		for(ll i=0;i<4;i++)
			scanf("%lld",vx+i);
		for(ll i=1;i<=n;i++)
			a[i]=va[i]^vx[va[i]%4];
		nk=0;
		ans[1]=1;
		for(ll i=2;i<=n;i++){
			if((ll)log2(i-2)<(ll)log2(i-1))
				nk++;
		}
		rx=0;
		for(ll i=1;i<=m;i++)
			rx^=(i*ans[q[i]]);
		printf("%lld\n",rx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
