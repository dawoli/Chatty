#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define int long long
#define INF 1e18
#define gc getchar()
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
int n,m;
char s[509];
int c[509];
int dp[500009][19];
int ppct(int x){
	int rt=0;
	rep(i,1,n){
		if(x&(1<<(i-1))) rt++;
	}
	return rt;
}
void md(int &x){x=(x>=mod?x-mod:x);}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n){
		cin>>s[i];
	}
	rep(i,1,m){
		c[i]=read();
	}
	dp[0][0]=1;
	rep(msk,1,(1LL<<n)-1){
		int mx=ppct(msk);
	//	cout<<msk<<" "<<mx<<endl;
		rep(i,1,n){
			if(msk&(1<<(i-1))){
				if(c[i]>0&&s[mx]=='1') dp[msk][0]+=dp[msk^(1<<(i-1))][0],md(dp[msk][0]);
				rep(j,1,mx){
					if(c[i]<=(j-1)||s[mx]=='0'){
						dp[msk][j]+=dp[msk^(1<<(i-1))][j-1],md(dp[msk][j]);
					}
					if(c[i]>j&&s[mx]=='1'){
						dp[msk][j]+=dp[msk^(1<<(i-1))][j],md(dp[msk][j]);
					}
				}
			}
		}
		
	}
	int ans=0;
	rep(i,0,n-m){
	//	printf("dp[%d]=%d\n",i,dp[(1<<n)-1][i]);
		ans+=dp[(1<<n)-1][i];
		md(ans);
	}
	cout<<ans<<endl;
	return 0;
}

