#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll n,maxa,a[5009],dp[5009][5009],ans;
ll qpow(int a,int b){
	if(!b) return 1;
	ll tmp=qpow(a,b/2);
	return tmp*tmp%M*(b%2?a:1)%M;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	maxa=a[n];
	for(int i=0;i<=maxa;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=maxa;j>=0;j--){
			dp[i][j]=dp[i-1][j];
			if(j-a[i]>=0) (dp[i][j]+=dp[i-1][j-a[i]])%=M;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<' '<<a[i]<<' '<<qpow(2,i-1)-dp[i-1][a[i]]<<endl;
		(ans+=qpow(2,i-1)+M-dp[i-1][a[i]])%=M;
	}
	cout<<ans<<endl;
	return 0;
}
