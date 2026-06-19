#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c;
ll t,n,a[100010][5],b[100010],dp[100010][5],max2,max3,sum,ans;
ll read(){
	ll ne=1,a=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')ne=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return ne*a;
}
void dfs(ll d,ll _sum,ll sa,ll sumb,ll sc){
	if(d==n){
		ans=max(ans,_sum);
		return;
	}
	if(sa<n/2)dfs(d+1,_sum+a[d+1][1],sa+1,sumb,sc);
	if(sumb<n/2)dfs(d+1,_sum+a[d+1][2],sa,sumb+1,sc);
	if(sc<n/2)dfs(d+1,_sum+a[d+1][3],sa,sumb,sc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			max2=max(max2,a[i][2]);
			max3=max(max3,a[i][3]);
		}
		memset(dp,0,sizeof(dp));
		if(!max2&&!max3){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			sum=0;
			for(int i=n;i>n/2;i--)sum+=b[i];
			printf("%lld\n",sum);
			continue;
		}
		if(n<=10){
			ans=0;
			dfs(0,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=dp[i-1][j];
				for(int k=1;k<=3;k++){
					dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
				}
			}
		}
		printf("%lld\n",max(max(dp[n][1],dp[n][2]),dp[n][3]));
	}
	return 0;
}
