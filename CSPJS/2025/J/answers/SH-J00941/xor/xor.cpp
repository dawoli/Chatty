#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
long long dp[1005][1005],xx[1005][1005];

int xn(int x,int y){
	int pow=1,ans=0;
	while(x!=0 || y!=0){
		if(x%2!=y%2)	ans+=pow;
		x/=2;
		y/=2;
		pow*=2;
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		xx[i][i]=a[i];
		if(a[i]==k)	dp[i][i]=1;
	}
	for(int t=2;t<=n;t++){
		for(int i=t;i<=n;i++){
			xx[t-1][i]=xn(xx[t-1][i-1],a[i]);
			if(xx[t-1][i]==k)	dp[t-1][i]=1;
		}
	}
	for(int len=1;len<=n;len++){
		for(int st=1;st<=n-len+1;st++){
			int end=st+len-1;
			for(int k=st;k<end;k++){
				dp[st][end]=max(dp[st][end],dp[st][k]+dp[k+1][end]);
			}
		}
	}
	cout << dp[1][n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
