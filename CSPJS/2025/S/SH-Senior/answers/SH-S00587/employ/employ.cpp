#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],dp[1<<18][18][2],ans,get_1;
char s[510];
int f(){
	int ans=1;
	for(int w=1;w<=n;w++)ans=1ll*ans*w%mod;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	if(n<=18){
		for(int w=0;w<n;w++)scanf("%d",&a[w]);
		dp[0][0][0]=1;
		for(int w=1;w<(1<<n);w++){
			int cnt=0;
			for(int x=0;w>>x;x++)cnt+=(w>>x&1);
			for(int x=0;x<n;x++)for(int y=0;w>>y;y++)if(w>>y&1){
				if(x<a[y]&&s[cnt]=='1')dp[w][x][1]=(1ll*dp[w-(1<<y)][x][0]+dp[w-(1<<y)][x][1]+dp[w][x][1])%mod;
				else if(x-1>=a[y]||s[cnt]=='0')if(x!=0)dp[w][x][0]=(1ll*dp[w-(1<<y)][x-1][0]+dp[w-(1<<y)][x-1][1]+dp[w][x][0])%mod;
			}
		}
		for(int x=0;x<=n-m;x++)ans=(1ll*ans+dp[(1<<n)-1][x][0]+dp[(1<<n)-1][x][1])%mod;
		printf("%d",ans);
	}else{
		for(int w=1;w<=n;w++)get_1+=(s[w]=='1');
		if(get_1<m)printf("0");
		else if(get_1==n||m==1)printf("%d",f());
		else printf("0");
	}
	return 0;
}
