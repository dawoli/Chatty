#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
const int MOD=998244353;
int n,m,ans;
int s[MAXN],c[MAXN],dp[MAXN];
void solve1(){
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		dp[c[i]]++;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		if(c[i+1]==c[i]) continue;
		for(int j=dp[c[i]]+min(c[i],n);j<=dp[c[i]];j++)
		ans*=(dp[c[i]]+min(c[i],n)-i);
	}
	cout<<ans<<endl;
}
void solve2(){
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(s[i]==0)
				break;
			else if(s[j]>sum){
				sum++;
			}
		}
		if(sum>=m) ans++;
		ans%=MOD;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ss;
		cin>>ss;
		s[i]=ss-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	bool b=1;
	for(int i=1;i<=n;i++){
		if(s[i]==0)
			b==0;
	}
	bool b1;
	for(int i=1;i<=n;i++){
		if(s[i]==1)
			b1==0;
	}
	if(b==1) solve1();
	else if(b1==1){
		int sum=0;
		sort(s+1,s+1+n);
		for(int i=1;i<=n;i++){
			if(s[i]==0) sum++;
			else break;
		}
		if(sum>=m) cout<<0<<endl;
		else       cout<<0<<endl;
	}
	else     solve2();
	return 0;
}
