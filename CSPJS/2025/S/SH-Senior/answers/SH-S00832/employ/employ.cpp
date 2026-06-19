#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
ll n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll cnt=n;
	for(int i=1;i<=n;i++){
		ll c;
		cin>>c;
		if(c==0) cnt--;
	}
	ll ans=1;
	for(int i=1;i<=cnt;i++) ans=(ans*i)%MOD;
	cout<<ans; 
	return 0;
}
