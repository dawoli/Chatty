#include<bits/stdc++.h>
using namespace std;
int n;
long long r[100005]={0},dp[100005]={0};
long long ans=1e5+8;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		r[x]++;
	}
	dp[1]=0;
	for(int i=2;i<=100007;i++){
		if(r[i]!=0){
			if(r[i-1]<=r[i]){
				dp[i]=dp[i-1]+r[i-1];
				r[i-1]=0;
				r[i]+=r[i-1];
			}else if(r[i-1]>r[i]){
				dp[i]=dp[i-1]+r[i];
				r[i-1]-=r[i];
				r[i]+=r[i-1];
			}	
		}else{
			r[i]=r[i-1];
			dp[i]=dp[i-1];
		}
	}
	for(int i=1;i<=100007;i++){
		ans=min(ans,n-dp[i]);
	}
	cout<<ans;
	return 0;
}
