#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9,M=(1LL<<20)+9;
//OK! code lenth less than T1!
ll n,k,a[N],f[N],g[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=0;i<M;i++) g[i]=-1e16;
	ll res=0;
	f[0]=0;g[0]=0;
	for(ll i=1;i<=n;i++){
		res^=a[i];
		f[i]=max(f[i-1],g[res^k]+1);
		g[res]=max(g[res],f[i]);
//		cout<<f[i]<<" ";
	}
	printf("%lld\n",f[n]);
	return 0;
}
