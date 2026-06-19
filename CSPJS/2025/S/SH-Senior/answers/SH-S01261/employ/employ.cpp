#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,cnt[505],pcnt[505],dp[505][505][505],ans;
int jc[505];string s;
const int modp=998244353;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	jc[0]=1;for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%modp;
	for(int i=1;i<=n;i++){int x;cin>>x;cnt[x]++;}
	for(int i=n;i>=0;i--)pcnt[i]=pcnt[i+1]+cnt[i];
	dp[0][0][cnt[0]]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=i;j++)for(int k=0;k<=n;k++){
		if(s[i]=='0')(dp[i+1][j+1][k+cnt[j+1]]+=dp[i][j][k])%=modp;
		else{
			(dp[i+1][j][k]+=dp[i][j][k])%=modp;
			if(k){(dp[i+1][j][k-1]+=dp[i][j][k]*(modp-k))%=modp;(dp[i+1][j+1][k-1+cnt[j+1]]+=dp[i][j][k]*k)%=modp;}
		}
	}
	for(int i=0;i<=n-m;i++)for(int j=0;j<=n;j++)(ans+=dp[n][i][j]*jc[j+pcnt[i+1]])%=modp;
	cout<<ans;
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

YES, I FINALLY DID IT!!!
( and what should i do after i had all-killed? i can't fall asleep )
*/
