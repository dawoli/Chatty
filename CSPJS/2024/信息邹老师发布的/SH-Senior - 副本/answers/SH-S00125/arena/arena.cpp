#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+5;
ll n,m,T,a[maxn],b[maxn],c[maxn],x[5];
char K[20][maxn];
bool los[maxn];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(ll i=1;i<=m;i++) scanf("%lld",&c[i]);
	ll times=0,p=n-1;
	while(p>0){
		times++;
		p>>=1;
	}
	for(ll i=1;i<=times;i++)
		for(ll j=1;j<=1<<(times-i);j++)
			scanf("\n%c",&K[i][j]);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&x[0],&x[1],&x[2],&x[3]);
		ll ans=0;
		for(ll i=1;i<=n;i++) a[i]=b[i]^x[i%4];
		for(ll i=1;i<=m;i++){
			memset(los,0,sizeof(los));
			ll time=0,pp=c[i]-1;
			while(pp>0){
				time++;
				pp>>=1;
			}
			for(ll j=1;j<=time;j++){
				ll cnt=0;
				for(ll k=1;k<=c[i];k++){
					while(k<=n&&los[k]) k++;
					if(k>n) break;
					ll p1=k;
					k++;
					while(k<=n&&los[k]) k++;
					if(k>n) break;
					ll p2=k;
					if(K[j][++cnt]=='0'){
						if(a[p1]>=j) los[p2]=1;
						else los[p1]=1;
					}
					else{
						if(a[p2]>=j) los[p1]=1;
						else los[p2]=1;
					}
				}
			}
			for(ll j=1;j<=c[i];j++) if(!los[j]){
				ans^=(i*j);
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
