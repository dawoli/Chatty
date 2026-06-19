#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int r[N],dp[N],cnt[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n,cmp);
	for(int i=1;i<=n;i++){
		cnt[r[i]]++;
	}
	dp[r[1]]=cnt[r[1]];
	for(int i=r[1]+1;i<=r[n];i++){
		if(cnt[i]==0)dp[i]=dp[i-1];
		else dp[i]=max(cnt[i],dp[i-1]);
	}
	cout<<dp[r[n]];
	return 0;
}

