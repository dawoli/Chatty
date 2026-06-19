#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[109];
ll ans=51;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	for(ll i=1;i<n;i++){
		if(s[i]!=s[i-1])
			ans--;
	}
	cout<<ans;
	return 0;
}
