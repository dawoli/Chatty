#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
map<ll,ll> mp[10];
int main(){	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
		ll ii=0,jj=0;
		if(s[0]=='C')ii=1;
		else if(s[0]=='D')ii=2;
		else if(s[0]=='S')ii=3;
		else ii=4;
		if(s[1]=='T')jj=10;
		else if(s[1]=='J')jj=11;
		else if(s[1]=='Q')jj=12;
		else if(s[1]=='K')jj=13;
		else if(s[1]=='A')jj=1;
		else jj=s[1]-'0';
		mp[ii][jj]++;
	}
	ll x=mp[1].size()+mp[2].size()+mp[3].size()+mp[4].size();
	printf("%lld",52-x);
	return 0;
}