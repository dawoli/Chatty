#include<bits/stdc++.h>
using namespace std;
long long dp[200001],he[1000001],to[200001],a[200001],hhh[200001],pre[200001],back[200001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			dp[i]=0;
			he[i]=0;
			hhh[i]=0;
			to[i]=0;
			back[i]=0;
			pre[i]=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j];
			he[a[j]]++;
			if(he[a[j]]>1){
				back[hhh[a[j]]]=j;
				to[j]=hhh[a[j]];
			}
			hhh[a[j]]=j;
		}
		for(int j=1;j<=n;j++){
			if(to[j]!=0){
				if(a[j]+dp[to[j]]>dp[j-1]){
					pre[j]=to[j];
					dp[j]=a[j]+dp[to[j]];
				}
				else{
					pre[j]=pre[j-1];
					dp[j]=dp[j-1];
				}
			}
			else{
				pre[j]=pre[j-1];
				dp[j]=dp[j-1];
			}
		}
		ans+=dp[n];
		for(int j=pre[n];j>=1;j=pre[j]){
			to[back[j]]=0;
		}
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		for(int j=1;j<=n;j++){
			if(to[j]!=0){
				if(a[j]+dp[to[j]]>dp[j-1]){
					dp[j]=a[j]+dp[to[j]];
				}
				else{
					dp[j]=dp[j-1];
				}
			}
			else{
				dp[j]=dp[j-1];
			}
		}
		cout<<ans+dp[n]<<endl;
	}
	
	return 0;
}
