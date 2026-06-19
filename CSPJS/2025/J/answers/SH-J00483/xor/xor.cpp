#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,bool> mp;
ll n,k,sum,ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	mp[0]=1;
	for(ll i=1,a; i<=n; ++i) {
		cin>>a,sum^=a;
		if(mp[sum^k]) mp.clear(),sum=0,++ans;
		mp[sum]=1;
	}
	cout<<ans;
	return 0;
}
