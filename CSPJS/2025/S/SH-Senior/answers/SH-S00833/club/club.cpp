#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N][4];
ll _f18(ll i,ll x,ll y,ll z){
	if(i>n) return 0;
	ll ans=0;
	if(x+1<=(n>>1)) ans=max(ans,a[i][1]+_f18(i+1,x+1,y,z));
	if(y+1<=(n>>1)) ans=max(ans,a[i][2]+_f18(i+1,x,y+1,z));
	if(z+1<=(n>>1)) ans=max(ans,a[i][3]+_f18(i+1,x,y,z+1));
	return ans;
}
void solve1_8(){
	printf("%lld\n",_f18(1,0,0,0));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%d",&T);
	while(T--){
//printf("hi\n");
		scanf("%d",&n);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		if(n<=10){ solve1_8(); continue; }
	}
	return 0;
}



