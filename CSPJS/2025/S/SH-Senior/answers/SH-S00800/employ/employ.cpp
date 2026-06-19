#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x[1009],mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool ok=1;
	for(int i=0;i<n;i++){
		cin>>x[i+1];
		if(s[i]!='1')ok=0;
	}
	if(ok){
		ll ans=1;
		while(n){
			ans=(ans*n)%mod;
			n--;
		}
		cout<<ans;
	}
	return 0;
}
