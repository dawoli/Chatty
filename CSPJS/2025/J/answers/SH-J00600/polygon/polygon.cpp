#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
#define INF 1e18
#define mod 998244353
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;
		char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=gc;
		}
		return x*f;
	}
}
using namespace fastIO;
const int L=5000;
int n;
int a[5009];
int cnt[10009];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	rep(i,1,n){
		a[i]=read();
	}
	cnt[0]=1;
	sort(a+1,a+n+1);
	rep(i,1,n){
		int nd=a[i]+1;
		rep(j,nd,L+1){
			ans=(ans+cnt[j])%mod;
		}
		Rep(j,L+1,0){
			int p=j+a[i];
			if(p>L){
				cnt[L+1]=(cnt[L+1]+cnt[j])%mod;
			}
			else{
				cnt[p]=(cnt[p]+cnt[j])%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

