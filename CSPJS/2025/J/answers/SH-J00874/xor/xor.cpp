#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009],s[500009],nxt[500009],dp[500009];
bool Max1(){
	for(int i=1;i<=n;i++) if(a[i]>1) return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(Max1()){
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans<<endl;
			return 0; 
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		int nw=s[i-1];
		for(int j=i;j<=n;j++){
			if((s[j]^nw)==k){
				nxt[i]=j;
				break;	
			}
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i]);
		if(nxt[i]!=0) dp[nxt[i]]=max(dp[i-1]+1,dp[nxt[i]]);
	}
	cout<<dp[n]<<endl;
	return 0;
}
