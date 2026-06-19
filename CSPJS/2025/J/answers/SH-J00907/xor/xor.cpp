#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
ll n,k,a[500009],amax;
namespace On2{
	ll sum[500009],dp[500009],ans[500009];
	void solve(){
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j>0;j--){
				if((sum[i]^sum[j-1])==k){
					dp[i]=max(1ll,ans[j-1]+1);
					break;
				}
			}
			ans[i]=max(ans[i-1],dp[i]);
		}
		cout<<ans[n]<<endl;
	}
}
namespace A255{
	ll sum,dp[500009],ans[500009],last[300],tgt[500009];
	void solve(){
		for(int i=1;i<=256;i++) last[i]=-1;
		for(int i=1;i<=n;i++){
			sum^=a[i];
			last[sum]=i;
			tgt[i]=last[k^sum]+1;
//			cout<<i<<' '<<tgt[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(tgt[i]) dp[i]=max(1ll,ans[tgt[i]-1]+1);
			ans[i]=max(ans[i-1],dp[i]);
		}
		cout<<ans[n]<<endl;
	}
}
namespace sol{
	ll sum,dp[500009],ans[500009],tgt[500009];
	map<ll,int> last;
	void solve(){
		last[0]=1;
		for(int i=1;i<=n;i++){
			sum^=a[i];
			last[sum]=i+1;
			tgt[i]=last[k^sum];
//			cout<<i<<' '<<tgt[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(tgt[i]) dp[i]=max(1ll,ans[tgt[i]-1]+1);
			ans[i]=max(ans[i-1],dp[i]);
		}
		cout<<ans[n]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amax=max(a[i],amax);
	}
	if(n<=1e4)
		On2::solve();
	else
	if(amax<=256)
		A255::solve(); 
	else
		sol::solve();
	return 0;
}
