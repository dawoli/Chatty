#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=5e3+5;
int n,a[N],mx;
ll g[N],f[N<<2];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=a[i]+1;j<=mx+5;j++) (g[i]+=f[j])%=mod;
		for(int j=(mx<<1)+5;j>=a[i];j--) (f[j]+=f[j-a[i]])%=mod;
		for(int j=mx+2;j<=(mx<<1)+5;j++) (f[mx+1]+=f[j])%=mod,f[j]=0;
	}
	ll ans=0;
	for(int i=3;i<=n;i++)
		(ans+=g[i])%=mod;
	cout<<ans;
	return 0;
}
