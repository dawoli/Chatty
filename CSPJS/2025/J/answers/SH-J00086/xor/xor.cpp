//This program will be TLE.
#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010],cnt,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cnt=0,s=0;
		for(int j=i;j>=1;j--){
			s^=a[j];
			if(s==k) s=0,cnt++;
			dp[i]=max(dp[i],cnt+dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
} 
