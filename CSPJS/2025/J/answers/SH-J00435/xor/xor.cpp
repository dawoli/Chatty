#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("xor.in","stdin",stdin);
	freopen("xor.out","stdout",stdout);
	int s[50005],n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int dp[50005],ans;
	dp[0]=0;
	if(s[1]==k){
		dp[1]=1;
	}else{
		dp[1]=0;
	}
	for(int r=2;r<=n;r++){
		for(int l=1;l<=r;l++){
			for(int i=l;i<=r;i++){
				if(i==l){
					ans=s[i];
				}else{
					ans=ans xor s[i];
				}
			}
			if(ans==k){
				dp[r]=max(dp[l],dp[l-1]+1);
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
