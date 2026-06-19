#include<bits/stdc++.h>
#define MOD 998244353
#define N 505
using namespace std;
typedef long long ll;
ll n,m,c[N],cnt=0,p[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(m==n){
		if(cnt<s.size()){
			cout<<0;
			return 0;
		}
		for(ll i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		ll ans=1;
		for(ll i=2;i<=n;i++){
			ans=(ans*i)%MOD;
		}
		cout<<ans;
	}
	else if(cnt==s.size()){
		ll tot=n;
		for(ll i=1;i<=n;i++){
			if(c[i]==0) tot--;
		} 
		if(tot<m) cout<<0;
		else{
			ll ans=1;
			for(ll i=2;i<=n;i++){
				ans=(ans*i)%MOD;
			}
			cout<<ans;
		}
	}
	else{
		for(ll i=1;i<=n;i++) p[i]=i;
		ll ans=0;
		do{
			ll d=0,tot=0;
			for(ll i=1;i<=n;i++){
				if(d>=c[p[i]]||s[i-1]=='0') d++;
				else tot++;
			}
			if(tot>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		ans%=MOD;
		cout<<ans;
	}
	return 0;
}

