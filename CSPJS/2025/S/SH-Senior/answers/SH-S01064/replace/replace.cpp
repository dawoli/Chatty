#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+8;
map<ll,ll> cnt;
string s[N][2];
string t[N][2];
ll a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		cin>>s[i][0]>>s[i][1];
		a[i]=s[i][0].find('b')-s[i][1].find('b');
		cnt[a[i]]++; 
	}
	for(ll i = 1;i <= m;i++){
		string t1,t2;
		cin>>t1>>t2;
		ll key=t1.find('b')-t2.find('b');
		cout<<cnt[key]<<"\n"; 
	}
	return 0;
} 
