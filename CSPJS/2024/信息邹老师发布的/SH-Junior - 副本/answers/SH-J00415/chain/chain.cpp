#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MaxN=200010;
ll T,n,m,k,pj;
ll ur[MaxN];
ll uc[MaxN];
ll ra[MaxN];
ll lw[MaxN];
ll hax[MaxN],ix;
ll ntx[MaxN];
pll vtx[MaxN];
ll cnt[MaxN];
bitset<MaxN>ans;
vector<ll>a[MaxN];
bool cmp(ll ra,ll rb){
	return ur[ra]<ur[rb];
}
int main(){
	//*/
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	//*/
	scanf("%lld",&T);
	while(T-->0){
		ix=0;pj=0;
		memset(cnt,0,sizeof(cnt));
		memset(hax,0,sizeof(hax));
		scanf("%lld%lld%lld",&n,&m,&k);
		for(ll i=1;i<=n;i++){
			scanf("%lld",lw+i);
			a[i].resize(lw[i]+1);
			for(ll j=1;j<=lw[i];j++)
				scanf("%lld",&(a[i][j]));
		}
		for(ll i=1;i<=k;i++){
			scanf("%lld%lld",ur+i,uc+i);
			ra[i]=i;
		}
		cnt[1]=1;
		sort(ra+1,ra+k+1,cmp);
		for(ll i,ji=1;ji<=k;ji++){
			i=ra[ji];
			for(;pj<ur[i];pj++){
			}
			ans[i]=1;
		}
		for(ll i=1;i<=k;i++)
			printf("%lld\n",(ll)ans[i]);
		for(ll i=1;i<=n;i++)
			a[i].resize(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
