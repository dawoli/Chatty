#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],dp[2][N],n;//cur lstbutnot-1'snum
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int maxx=-1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),maxx=max(maxx,a[i]);
		if(n*maxx>4e6)break;
		int s=0;
		for(int i=2;i<=n;++i)if(a[i]!=a[i-1]){s=i;break;}
		if(s==0){printf("%d\n",(n-1)*a[1]);continue;}
		for(int i=1;i<=maxx;++i)dp[s&1][i]=-1e9;
		dp[s&1][a[1]]=(s-2)*a[1];//cout<<s<<endl;
		for(int i=s+1;i<=n;++i){
			for(int j=1;j<=maxx;++j)dp[i&1][j]=-1e9;
			for(int j=1;j<=maxx;++j){//shuabiao
				dp[i&1][j]=max(dp[i&1][j],dp[i&1^1][j]+(a[i]==a[i-1]?a[i]:0));
				dp[i&1][a[i-1]]=max(dp[i&1][a[i-1]],dp[i&1^1][j]+(a[i]==j?j:0));
			}//for(int j=1;j<=maxx;++j)cout<<i<<' '<<j<<' '<<dp[i&1][j]<<endl;
		}
		int ans=0;
		for(int i=1;i<=maxx;++i)ans=max(ans,dp[n&1][i]);
		printf("%d\n",ans);
	}
}			
