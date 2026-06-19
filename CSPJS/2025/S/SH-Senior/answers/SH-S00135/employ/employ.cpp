#include<bits/stdc++.h>
using namespace std;
const int N=505;
#define ll long long
const ll mod=998244353;
ll a[N],pap[N];string s;
ll n,m;ll ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	bool flag=0;
	for(ll i=0;i<n;i++){
		pap[i]=s[i]-'0';
		if(pap[i]==0)flag=1;
	}
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(!flag){
		ans=1;
		for(ll i=1;i<=n;i++)ans=(ans*i)%mod;
		ans%=mod;cout<<ans;return 0;
	}
	if(m==1){
		if(pap[0]==1){
			ans=1;
			for(ll i=1;i<=n;i++)ans=(ans*i)%mod;
			ans%=mod;cout<<ans;return 0;
		}else if(pap[0]==0){
			ans=0;
			for(ll i=1;i<=n;i++)
				if(a[i]>=1)ans++;
			ans%=mod;
			for(ll i=1;i<=n-1;i++)ans=(ans*i)%mod;
			ans%=mod;cout<<ans;return 0;
		}
	}
}
