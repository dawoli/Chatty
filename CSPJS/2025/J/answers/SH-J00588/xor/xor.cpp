#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=500005;
ll n,k,a[N],f[N],s[N],g[(1<<20)+9];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	s[0]=0;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(ll i=0;i<(1<<20);++i)g[i]=-1;
	g[k]=0;
	f[0]=0;
	for(ll i=1;i<=n;++i){
		f[i]=f[i-1];
		if(g[s[i]]>=0)f[i]=max(f[i],f[g[s[i]]]+1);
		g[s[i]^k]=i;
	}
	cout<<f[n]<<"\n";
	return 0;
}
