#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N];
int dp[N];
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	dp[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[j]>r[i]){
				dp[j]=max(dp[j],dp[i]+1);
				ans=max(ans,dp[j]);
			}
		}
	}
	printf("%d",n-ans);
	return 0;
}
