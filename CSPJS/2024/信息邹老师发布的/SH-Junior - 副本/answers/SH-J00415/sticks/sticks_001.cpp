#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ww[20]={6,2,5,5,4,5,6,3,7,6};
ll T,n,ans;
ll dp[60];
int main(){
	ll ry;
	memset(dp,0x3f,sizeof(dp));
	//*/
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	//*/
	for(ll i=1;i<=9;i++)
		dp[ww[i]]=min(dp[ww[i]],i);
	for(ll i=2;i<=50;i++)
		for(ll j=0;j<=9;j++) if(i-1>ww[j])
			dp[i]=min(dp[i],dp[i-ww[j]]*10+j);
	scanf("%lld",&T);
	while(T-->0){
		scanf("%lld",&n);
		if(n==1){
			puts("-1");
		}else{
			ry=max((ll)0,(n-28)/7);
			n-=ry*7;
			printf("%lld",dp[n]);
			while(ry-->0)
				putchar('8');
			putchar(10);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
