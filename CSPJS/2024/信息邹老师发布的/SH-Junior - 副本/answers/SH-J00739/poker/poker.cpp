#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		string name;
		cin>>name;
		s.insert(name);
	}
	ll cnt=s.size();
	ll ans=52-cnt;
	printf("%lld",ans);
	return 0;
}
