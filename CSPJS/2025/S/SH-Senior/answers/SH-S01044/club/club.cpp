#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long a[100005][4],sub1[100005];
long long dp[105][105][105];
void dfs(long long ga,long long gb,long long gc,long long sum){
	if(ga+gb+gc==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(ga<n/2)dfs(ga+1,gb,gc,sum+a[ga+gb+gc][1]);
	if(gb<n/2)dfs(ga,gb+1,gc,sum+a[ga+gb+gc][2]);
	if(gc<n/2)dfs(ga,gb,gc+1,sum+a[ga+gb+gc][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		cin>>n;
		long long f=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if((j==2||j==3)&&a[i][j]!=0)f=1;
			}
		}
		if(f==0){
			for(long long i=1;i<=n;i++){
				sub1[i]=a[i][1];
			}
			sort(sub1,sub1+1+n);
			for(long long i=n/2+1;i<=n;i++){
				ans+=sub1[i];
			}
			printf("%lld\n",ans);
			continue;
		}
//		for(long long i=1;i<=n;i++){
			for(long long ga=0;ga<=n/2;ga++){
				for(long long gb=0;gb<=n/2;gb++){
					for(long long gc=0;gc<=n/2;gc++){
						dp[ga][gb][gc]=0;
					}
				}
			}
//		}
			for(long long ga=0;ga<=n/2;ga++){
				for(long long gb=0;gb<=n/2;gb++){
					for(long long gc=0;gc<=n/2;gc++){
						if(ga>0)dp[ga][gb][gc]=max(dp[ga][gb][gc],dp[ga-1][gb][gc]+a[ga+gb+gc][1]);
						if(gb>0)dp[ga][gb][gc]=max(dp[ga][gb][gc],dp[ga][gb-1][gc]+a[ga+gb+gc][2]);
						if(gc>0)dp[ga][gb][gc]=max(dp[ga][gb][gc],dp[ga][gb][gc-1]+a[ga+gb+gc][3]);
					}
				}
			}
			for(long long ga=0;ga<=n/2;ga++){
				for(long long gb=0;gb<=n/2;gb++){
					for(long long gc=0;gc<=n/2;gc++){
						if(ga+gb+gc==n)ans=max(ans,dp[ga][gb][gc]);
//						cout<<dp[ga][gb][gc][i]<<" ";
					}
//					cout<<endl;
				}
//				cout<<endl;
			}
//			cout<<endl;
//		dfs(0,0,0,0);
		printf("%lld\n",ans);
	}
} 
