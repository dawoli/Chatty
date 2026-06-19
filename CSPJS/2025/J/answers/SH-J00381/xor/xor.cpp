#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+1;
long long n,k,a[N],b[N],c[N],d[1048577],dp[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=k;
	for(long long i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1],b[i]=a[i]^k;
	for(long long i=1;i<=1048576;i++) d[i]=-1;
	c[0]=-1;
	d[b[0]]=0;
	for(long long i=1;i<=n;i++) c[i]=d[a[i]],d[b[i]]=i;
	for(long long i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(c[i]+1) dp[i]=max(dp[i],dp[c[i]]+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}
