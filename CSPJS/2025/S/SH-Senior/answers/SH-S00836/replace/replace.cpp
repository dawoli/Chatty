#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2e5+9;

ll n, q, sz1, sz2;
string x, y;
string s1, s2;

map<string, string> mp;
struct node{
	ll pre1, lst1, pre2, lst2;
}cnt[N];

void solve1(){
	ll ans=0;
	for(ll i=-1; i<sz1; i++){
		if(i>=0&&x[i]!=y[i]) break;
		string mid1, mid2;
		for(ll j=i+1; j<sz1; j++){
			mid1+=x[j]; mid2+=y[j];
			if(mp[mid1] != mid2) continue;
			ll bomb = 0;
			for(ll k=j+1; j<sz1; j++)
				if(x[k]!=y[k]){
					bomb=1;
					break;
				} 
			if(bomb==0) ans++;
		}
	}
	cout<<ans<<'\n';
}

vector<ll> es[N];
ll fabs(ll x){
	return max(x, -x);
}
void solve2(){
	ll ans=0;
	ll pre3, lst3, pre4, lst4;
	for(ll j=0; j<sz1; j++)
		if(x[j]=='b') pre3 = j, lst3 = sz1-j-1;
	for(ll j=0; j<sz1; j++)
		if(y[j]=='b') pre4 = j, lst4 = sz1-j-1;
	ll k = fabs(pre3-pre4);
	for(ll i=0; i<es[k].size(); i++){
		ll id=es[k][i];
		if(pre3>=cnt[id].pre1&&lst3>=cnt[id].lst1&&pre4>=cnt[id].pre2&&lst4>=cnt[id].lst2)
			ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>q;
	for(ll i=1; i<=n; i++){
		cin>>s1>>s2;
		ll sz = s1.size();
		if(sz<=3000) mp[s1] = s2;
		for(ll j=0; j<sz; j++)
			if(s1[j]=='b') cnt[i].pre1 = j, cnt[i].lst1 = sz-j-1;
		for(ll j=0; j<sz; j++)
			if(s2[j]=='b') cnt[i].pre2 = j, cnt[i].lst2 = sz-j-1;
		es[fabs(cnt[i].pre2-cnt[i].pre1)].push_back(i);
	}
	
	for(ll i=1; i<=q; i++){
		cin>>x>>y;
		sz1 = x.size();
		sz2 = y.size();
		if(sz1!=sz2)
			cout<<0<<'\n';
		else if(sz1<=2000)
			solve1();
		else
			solve2();
	}
	
	return 0;
}
