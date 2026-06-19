//40pts
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5005;
const int M = 1e6 + 1e4;
const int mod = 998244353;
int n,a[N],b[N];
int s[N],dp[M],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		int mm=s[i-1]-a[i]-1;
		if(mm<0){
			continue;
		}
		for(int j=0;j<=mm;j++){
			dp[j]=0;
		}
		dp[0]=1;
		for(int j=1;j<=i-1;j++){
			for(int k=mm;k>=a[j];k--){
				dp[k]+=dp[k-a[j]];
				if(dp[k]>=mod)dp[k]-=mod;
			}
		}
		int sum=0;
		for(int j=0;j<=mm;j++){
			sum+=dp[j];
			if(sum>=mod)sum-=mod;
		}
		ans+=sum;
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
