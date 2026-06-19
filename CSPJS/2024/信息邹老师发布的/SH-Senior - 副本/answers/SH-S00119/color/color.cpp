#include<bits/stdc++.h>
using namespace std;
int a[200005];
int pre[200005];
long long int dp[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	long long int ans;
	for(int ti=0;ti<t;ti++){
		memset(pre,-1,sizeof(pre));
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i!=0){
				for(int j=i-1;j>=0;j--){
					if(a[i]==a[j]){
						pre[i]=j;
						break;
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			long long int m=0;
			if(pre[i]!=-1){
				for(int j=i-2;j>pre[i];j--){
					if(a[j]==a[j+1]){
						m+=a[j];
					}
				}
				if(pre[i]!=i-1) m+=dp[pre[i]+1];
				m+=a[i];
			}
			dp[i]=max(m,dp[i-1]);
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
