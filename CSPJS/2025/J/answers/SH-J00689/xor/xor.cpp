#include<iostream>
#define debug(x) (cerr<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=500005;
int a[N],nxt[N],s[N],dp[N];
int pos[1<<21];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	for(int i=0;i<(1<<20);i++) pos[i]=n+1;
	for(int i=n;i>=0;i--) nxt[i]=pos[a[i]^k],pos[a[i]]=i;
	for(int i=n;i>=0;i--) {
		dp[i]=dp[i+1];
		if(nxt[i]!=n+1) dp[i]=max(dp[i],dp[nxt[i]]+1);
	}
	cout<<dp[0];
	return 0;
}


