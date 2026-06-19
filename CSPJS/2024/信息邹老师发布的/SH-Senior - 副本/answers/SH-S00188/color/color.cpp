#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[200000+10],last[1000000+10],lastp[200000+10],dp[1000000+10][3],tag=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("color2.in","r",stdin);
	freopen("color.out","w",stdout); 
	cin>>t;
	//上天不会辜负 坚持的人!!! 
	while(t--){
		tag=0;
		memset(last,0,sizeof(last));
		memset(lastp,0,sizeof(lastp));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			lastp[i]=last[a[i]];
			last[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				tag+=a[i];
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
				continue;
			} 
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
			if(lastp[i]){
				dp[i][1]=max(max(dp[lastp[i]][1],dp[lastp[i]][0]),max(dp[lastp[i]+1][1],dp[lastp[i]+1][0]))+a[i];
			}
		}
		cout<<max(dp[n][0],dp[n][1])+tag<<endl;
	} 
}
