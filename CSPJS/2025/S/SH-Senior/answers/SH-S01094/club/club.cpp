#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ll long long
int T,n,k,t[N];ll a[N],b[N],c[N],f[N],g[N];
int readint(){
	static char c;
	static int r;r=0;
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r;
}
void work(){
	n=readint();
	for(int i=1;i<=n;++i)a[i]=readint(),b[i]=readint(),c[i]=readint();
	int x=0,y=0,z=0,d,m=n/2;ll ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]>=b[i]&&a[i]>=c[i])++x,t[i]=1,ans+=a[i],f[i]=min(a[i]-b[i],a[i]-c[i]);
		else if(b[i]>=c[i]&&b[i]>=a[i])++y,t[i]=2,ans+=b[i],f[i]=min(b[i]-c[i],b[i]-a[i]);
		else ++z,t[i]=3,ans+=c[i],f[i]=min(c[i]-a[i],c[i]-b[i]);
	}
	if(x<=m&&y<=m&&z<=m){
		printf("%lld\n",ans);
		return;
	}
	if(x>m)d=1;
	else if(y>m)d=2;
	else d=3;
	k=0;
	for(int i=1;i<=n;++i)if(t[i]==d)g[++k]=f[i];
	sort(g+1,g+k+1);
	for(int i=1;i<=k-m;++i)ans-=g[i];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=readint();
	while(T--)work();
	return 0;
}

