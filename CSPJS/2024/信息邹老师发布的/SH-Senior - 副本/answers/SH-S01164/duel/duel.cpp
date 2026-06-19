#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,a[N],ans;
multiset<ll> s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		if(!s.empty()&&a[i]>*s.begin())
			s.erase(s.begin()),++ans;
		s.insert(a[i]);
	}
	cout<<n-ans;
	return 0;
}
