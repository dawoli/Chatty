#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n,a[N],sum[N],k,nowmax;
map<int,int> dp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]^a[i];
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		int x = sum[i]^k;
		if(dp.find(x)!=dp.end()){
			nowmax = max(nowmax,dp[x]+1);
		}
		dp[sum[i]] = max(dp[sum[i]],nowmax);
	}
	printf("%d",nowmax);
	return 0;
}
