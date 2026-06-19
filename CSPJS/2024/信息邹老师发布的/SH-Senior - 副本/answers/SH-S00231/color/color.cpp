#include<bits/stdc++.h>
using namespace std;
long long vis[1000100];
long long n,a[200100],dp[200100],t,s,tmp=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(vis[a[i]]!=0){
				if(a[i]==a[s-1]){
					tmp=0;
					for(int j=vis[a[i]]+1;j<=i;j++){
						if(a[j-1]==a[j]){
							tmp+=a[j];
						}
					}
					dp[i]=max(dp[i-1]+a[i],max(dp[i-1],dp[vis[a[i]]]+a[i]+tmp));
					if(dp[i]==dp[vis[a[i]]]+a[i]+tmp||dp[i]==dp[i-1]+a[i]){
						s=i;
					}
				}
				else{
					tmp=0;
					for(int j=vis[a[i]]+1;j<i;j++){
						if(a[j-1]==a[j]){
							tmp+=a[j];
						}
					}
					dp[i]=max(dp[i-1],dp[vis[a[i]]]+a[i]+tmp);
					if(dp[i]==dp[vis[a[i]]]+a[i]+tmp){
						s=i;
					}
				}
			}
			else{
				dp[i]=dp[i-1];
			}
			vis[a[i]]=i;
		}
		cout<<dp[n]<<endl;
		for(int i=1;i<=1000099;i++){
			vis[i]=0;
			if(i<=100099){
				dp[i]=0;
			}
		}
	}
} 
