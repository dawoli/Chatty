#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,MOD=998244353;
ll c[N],n,m;
string s;
bool al1(){
	for(ll i=0;i<n;i++)if(s[i]=='0')return 0;
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	if(al1()){
		ll ans=1,nc=n;
		for(ll i=1;i<=n;i++)if(c[i]==0)nc--;
		if(nc<m)cout<<0;
		else{
			for(ll i=1;i<=nc;i++)ans=ans*i%MOD;
			cout<<ans;
		}
	}else if(m==n)cout<<0;
	return 0;
}
