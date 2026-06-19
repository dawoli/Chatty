#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int n,a[N],op[N],dp[N][2];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int maxx=-1;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1)))op[j]=1;
				else op[j]=0;
			}
			int ans=0;
			int last1=0,last0=0;
			else last0=1;
			if(op[1]==1)last1=1;
			for(int j=2;j<=n;j++){
				if(op[j]==1)ans+=(a[j]==a[last1])?a[j]:0,last1=j;
				else ans+=(a[j]==a[last0])?a[j]:0,last0=j; 
			}
			maxx=max(maxx,ans);
		}
		printf("%lld\n",maxx);
	}
	
	
	return 0;
}
