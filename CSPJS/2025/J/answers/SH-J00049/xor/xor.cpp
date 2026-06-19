#include<bits/stdc++.h>
using namespace std;
int a[500100],dp[500100],ans,n,k;
int xsum[500100],vis[500100];
int Xor(int a,int b){
	int p1=a,p2=a;
	p1|=b,p2&=b;
	return p1-p2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		xsum[i]=Xor(xsum[i-1],a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			if(Xor(xsum[i],xsum[i-j-1])==k){
				dp[i]=max(dp[i],dp[i-j-1]+1);
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
