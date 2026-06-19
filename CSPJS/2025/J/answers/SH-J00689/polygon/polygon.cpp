#include<iostream>
#include<algorithm>
#include<cstring>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=5005;
ll const MOD=998244353;
ll a[N],s[N];
ll p=1,dp[N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	sort(a+1,a+n+1);
	ll ans=0;
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		(ans+=p)%=MOD;
		p=p*2%MOD;
		for(int j=0;j<=a[i];j++) (ans+=MOD-dp[j])%=MOD;
		for(int k=min(a[n],s[i]);k>=a[i];k--) (dp[k]+=dp[k-a[i]])%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}


