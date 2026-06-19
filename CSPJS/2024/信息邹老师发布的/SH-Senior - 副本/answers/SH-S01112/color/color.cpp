#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
mt19937_64 rd(time(0));
int t;
int n,a[N],dp[N],z[N],p[2],g[N*5],ant;
int s[N];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i),s[i]=(a[i]==a[i-1])*a[i]+s[i-1];
		memset(g,-0x3f,sizeof g);
		dp[1]=0;
		ant=0;
		g[a[1]]=0;
		int c=1;
		for(int i=2;i<=n;i++){
			dp[i]=max(ant,g[a[i]])+s[i-1];
			ant=max(ant,dp[i]-s[i]);
			g[a[i-1]]=max(g[a[i-1]],dp[i]-s[i]+a[i-1]);
		}
		printf("%lld\n",ant+s[n]);
	}
}
