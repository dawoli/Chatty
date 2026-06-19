#include<bits/stdc++.h>
#define N 200009
#define A 1000009
#define ll long long
using namespace std;
int n,a[N],maxx;
ll dp[A],tmp,dmax;
void solve(){
	memset(dp,-1,sizeof(dp));tmp=0;dmax=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),maxx=max(maxx,a[i]);
	dp[0]=0;
	for(int i=2;i<=n;i++){
		dp[a[i-1]]=max(dp[a[i-1]],dmax);
		if(a[i]==a[i-1]){
			tmp+=a[i];
//	for(int i=1;i<=maxx;i++)printf("%d ",dp[i]);puts("");
			continue;
		}
		if(dp[a[i]]!=-1) dp[a[i-1]]=max(dp[a[i]]+a[i],dp[a[i-1]]);
		dmax=max(dmax,dp[a[i-1]]);
//	for(int i=1;i<=maxx;i++)printf("%d ",dp[i]);puts("");
	}
	printf("%lld\n",*max_element(dp,dp+maxx+1)+tmp);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}
