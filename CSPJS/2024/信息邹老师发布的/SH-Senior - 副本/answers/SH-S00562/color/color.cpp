#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define INF 1e9
#define int long long
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
int n,a[200009],ansb,T;
bool chs[200009];
int ts[1000009];
vector<int> nll;
int sum[200009][2],dp[200009][2];
void dfs(int l){
	if(l==(n+1)){
		int lst0=0,lst1=0,rt=0;
		rep(i,1,n){
			if(chs[i]==0){
				 if(a[i]==a[lst0]) rt+=a[i];
				 lst0=i;
			}
			else{
				if(a[i]==a[lst1]) rt+=a[i];
				lst1=i;
			}
		}
		ansb=max(ansb,rt);
		return;
	}
	chs[l]=0;
	dfs(l+1);
	chs[l]=1;
	dfs(l+1);
}
void solve(){
	sum[0][0]=0;
	sum[1][0]=0;
	rep(i,1,n){
		int lst=ts[a[i]];
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		rep(k,0,1){
			if(lst==-1){
				dp[i][k]=max(dp[i-1][k],dp[i-1][!k]);
				continue;
			}
			if((dp[lst][k]+sum[i-1][!k]-sum[lst][!k]+a[i])>=(max(dp[i-1][k],dp[i-1][!k]))){
				sum[i][k]+=a[i];
			}
			dp[i][k]=max(max(dp[i-1][k],dp[i-1][!k]),dp[lst][k]+sum[i-1][!k]-sum[lst][!k]+a[i]);
		}
		ts[a[i]]=i;
	}
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--){
		ansb=0;
		n=read();
		int tp=0;
		a[0]=-1;
		rep(i,1,n){
			a[i]=read();
			tp=max(tp,a[i]);
		}
		rep(i,1,tp){
			ts[i]=-1;
		}
		if(n<=15){
			dfs(1);
			cout<<ansb<<endl;
		}
		else{
			solve();
			cout<<max(dp[n][1],dp[n][2])<<endl;
		}
	}
	return 0;
}

