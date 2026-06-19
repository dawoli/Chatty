#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define Rep(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
inline void chkmax(int&x,int y){if(x<y)x=y;}
const int N=2e5+5,M=1e6+5;
int T,n,a[N],c[N],f[N],g[M];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	for(cin>>T;T--;){
		cin>>n;
		memset(f,0,sizeof f);
		memset(g,0xcf,sizeof g);
		rep(i,1,n)cin>>a[i],c[i]=c[i-1]+(a[i]==a[i-1]?a[i]:0);
		int ma=0;
		rep(i,1,n){
			f[i]=c[i-1]+max(ma,g[a[i]]+a[i]);
			chkmax(ma,f[i]-c[i]);
			chkmax(g[a[i-1]],f[i]-c[i]);
		}
		int ans=0;
		rep(i,1,n)ans=max(ans,f[i]+c[n]-c[i]);
		cout<<ans<<endl;
	}
	return 0;
}
