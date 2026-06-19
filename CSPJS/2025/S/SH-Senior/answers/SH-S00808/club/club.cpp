#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+9;
ll T,n,maxn;
ll p[N][5],ans,siz[5],sum[N],dp[N][5][5];
struct pl{
	int a,b,x;
}st[N];
bool cmp(pl &a,pl &b){
	return a.x>b.x;
}
void dfs(int cnt){
	if(cnt==n+1 || ans+sum[cnt]<=maxn){
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(siz[i]<n/2){
			siz[i]++;
			ans+=p[cnt][i];
			dfs(cnt+1);
			siz[i]--;
			ans-=p[cnt][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i][1],&p[i][2],&p[i][3]);
			if(p[i][3]==0) cnt++;
		} 
		maxn=-1;
		if(n<=30){//40pts
			memset(sum,0,sizeof(sum));
			for(int i=n;i>=1;i--){
				sum[i]=sum[i+1]+max(max(p[i][1],p[i][2]),p[i][3]);
			}
			dfs(1);
			cout<<maxn<<endl;
		}else if(cnt==n){//A,B 20pts
			for(int i=1;i<=n;i++){
				st[i].a=p[i][1];
				st[i].b=p[i][2];
				st[i].x=p[i][1]-p[i][2];
			}
			sort(st+1,st+1+n,cmp);
			for(int i=1;i<=n/2;i++) maxn+=st[i].a;
			for(int i=n/2+1;i<=n;i++) maxn+=st[i].b;
			cout<<maxn+1<<endl;
		}else{//C 10pts
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(dp[i][j][j]<=n/2){
						dp[i][j][j]++;
						dp[i][j][0]=max(max(dp[i-1][1][0],dp[i-1][2][0]),dp[i-1][3][0])+p[i][j];
						if(dp[i-1][1][0]>=dp[i-1][2][0]&&dp[i-1][1][0]>=dp[i-1][3][0]){
							dp[i][j][1]=dp[i-1][1][1];
							dp[i][j][2]=dp[i-1][1][2];
							dp[i][j][3]=dp[i-1][1][3];
						}else if(dp[i-1][1][0]<=dp[i-1][2][0]&&dp[i-1][2][0]>=dp[i-1][3][0]){
							dp[i][j][1]=dp[i-1][2][1];
							dp[i][j][2]=dp[i-1][2][2];
							dp[i][j][3]=dp[i-1][2][3];
						}if(dp[i-1][3][0]>=dp[i-1][2][0]&&dp[i-1][1][0]<=dp[i-1][3][0]){
							dp[i][j][1]=dp[i-1][3][1];
							dp[i][j][2]=dp[i-1][3][2];
							dp[i][j][3]=dp[i-1][3][3];
						}
					}
				}
			}
			for(int i=1;i<=3;i++) maxn=max(maxn,dp[n][i][0]);
			cout<<maxn<<endl;
		}
	}	
	return 0;
}
