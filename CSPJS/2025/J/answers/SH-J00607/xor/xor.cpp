#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[500005];
int n,k,a,ans;
int dp[500005];
int yh(int x,int y){
	bool x1,y1;
	int ret; 
	for(int i=0;i<=7;i++){
		x1=x%2;
		x/=2;
		y1=y%2;
		y/=2;
		ret+=abs(x1-y1)*pow(2,i);
	}
	return ret;
}
int f(int now,int nu,int t){
	if(now==0){
		return 500005;
	}
	if(nu==t){
		return now;
	}
	int nw;
	nw=num[now-1];
	nw=yh(nw,nu);
	return f(now-1,nw,t);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	dp[500004]=-2;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[f(i,num[i],k)-1]+1);
	}
	cout<<dp[n];
	return 0;
}
