#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
#define INF 1e18
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
int n,k;
int mx[1<<21];
int s[500009];
int a[500009];
int dp[500009];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	rep(i,1,(1LL<<20)) mx[i]=-INF;
	rep(i,1,n){
		a[i]=read();
		s[i]=s[i-1]^a[i];
		dp[i]=max(dp[i-1],mx[s[i]^k]+1);
		mx[s[i]]=max(mx[s[i]],dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}

