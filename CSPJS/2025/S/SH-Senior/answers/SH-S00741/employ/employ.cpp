#include<bits/stdc++.h>
#define N 509
#define p 998244353ll
#define ll long long
using namespace std;
int n,m;
char tmp[N];
int a[N],c[N];
namespace bf{
	ll f[262144][20];
	void solve(){
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int t=__builtin_popcount(i);
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					int x=i^(1<<j);
					for(int k=0;k<t;k++){
						if(c[j+1]>k&&a[t])f[i][k]+=f[x][k];
						else f[i][k+1]+=f[x][k];
					}
				}
			}
			for(int j=0;j<n;j++)f[i][j]%=p;
		}
		int t=(1<<n)-1;ll ans=0;
		for(int i=0;i<=n-m;i++)ans+=f[t][i];
		cout<<ans%p<<"\n";
	}
}
namespace AAA{
	ll f[N][N];
	void solve(){
		sort(c+1,c+n+1);
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if(j<c[i])f[i][j]+=f[i-1][j]*i%p;
				else{
					f[i][j+1]+=f[i-1][j]*(j-c[i]+1)%p;
					f[i][j]+=f[i-1][j]*(i-j+c[i]-1)%p;
				}
			}
			for(int j=0;j<=i;j++)f[i][j]%=p;
		}
		ll ans=0;for(int i=0;i<=n-m;i++)ans+=f[n][i];
		cout<<ans%p<<"\n";
	}
}
namespace CCC{
	int b[N],d[N];
	void solve(){
		sort(c+1,c+n+1);for(int i=1;i<=n;i++)d[c[i]]++;for(int i=1;i<=n;i++)d[i]+=d[i-1];
		for(int i=1;i<=n;i++)b[i]=a[i]?i-1:n;sort(b+1,b+n+1);
		ll ans=1;for(int i=1;i<=n;i++)ans=ans*max(0,d[b[i]]-i+1)%p;
		ll res=1;for(int i=1;i<=n;i++)res=res*i%p;
		cout<<(res+p-ans)%p<<"\n";
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>(tmp+1);
	for(int i=1;i<=n;i++)cin>>c[i],a[i]=tmp[i]^48;
	if(n<=18){bf::solve();return 0;}
	bool flag=1;for(int i=1;i<=n;i++)flag&=a[i];
	if(flag){AAA::solve();return 0;}
	if(m==n){cout<<0<<"\n";return 0;}
	if(m==1){CCC::solve();return 0;}
	return 0;
}
