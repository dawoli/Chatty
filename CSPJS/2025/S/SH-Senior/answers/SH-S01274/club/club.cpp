#include<bits/stdc++.h>
using namespace std;

long long t,n,ans,cnt,dp[100][100][100];
struct node{
	long long id,a,b,c;
}s[100010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		for(int i=1;i<=n;i++){
			for(int p=n/2;p>=0;p--){
				for(int q=n/2;q>=0;q--){
					for(int r=n/2;r>=0;r--){
						cnt=0;
						if(p!=0){
							dp[p][q][r]=dp[p-1][q][r]+s[i].a;
							cnt=1;
						}
						if(q!=0){
							dp[p][q][r]=max(cnt*dp[p][q][r],dp[p][q-1][r]+s[i].b);
							cnt=1;
						}
						if(r!=0) dp[p][q][r]=max(cnt*dp[p][q][r],dp[p][q][r-1]+s[i].c);
						ans=max(ans,dp[p][q][r]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
