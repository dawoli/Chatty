#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int S=1<<21;
char buf[S],*p1,*p2;
inline int nc(){
	if(p1==p2){
		p2=(p1=buf)+cin.read(buf,S).gcount();
		if(p1==p2)return EOF;
	}return *p1++;
}
inline int rd(){
	char ch;
	while(!isdigit(ch=nc()));
	int x=ch&0xf;
	while(isdigit(ch=nc()))x=x*10+(ch&0xf);
	return x;
}
constexpr int N=2e5+9,M=1e6+9,INF=0x3f3f3f3f;
int n,a[N];
ll sum[N],f[N],g[N],mx[M];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int T=rd();T;--T){
		n=rd();
		for(int i=1;i<=n;++i){
			mx[a[i]=rd()]=~INF;
			sum[i]=sum[i-1]+(a[i]==a[i-1]?a[i]:0);
		}
		for(int i=1;i<=n;++i){
			f[i]=max({f[i-1],g[i-1],mx[a[i]]+sum[i-1]+a[i]});
			g[i]=a[i]==a[i-1]?max({f[i-1],g[i-1]})+a[i]:~INF;
			if(i)mx[a[i-1]]=max(mx[a[i-1]],f[i]-sum[i]);
		}
		cout<<max(f[n],g[n])<<'\n';
	}
	return cout<<flush,0;
}
