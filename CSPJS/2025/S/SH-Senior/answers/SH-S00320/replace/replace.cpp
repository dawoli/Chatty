#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
#define ull unsigned long long
ll n,q;
map<ull,ull> mp;
void solve(string s,string t){
	ll szs=s.size(),szt=t.size();
	ull sn=0,tn=0;
	for(ll i=0;i<s.size();i++){
		sn=sn*27+s[i]-'a'+1;
	}
	for(ll i=0;i<t.size();i++){
		tn=tn*27+t[i]-'a'+1;
	}
	mp[sn]=tn;
}
ll que(string s,string t,ll bg,ll ed){
	ll cnt=0;
	for(ll i=0;i<=bg;i++){
		ull ys=0,yt=0;
		for(ll k=i;k<ed;k++) ys=ys*27+s[k]-'a'+1,yt=yt*27+t[k]-'a'+1;
		for(ll j=ed;j<s.size();j++){
			ys=ys*27+s[j]-'a'+1; yt=yt*27+t[j]-'a'+1;
			if(mp[ys]==yt) cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		solve(s,t);
	}
	for(ll i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		if(t.size()!=s.size()){
			cout<<0<<'\n'; continue;
		}
		ll bg=-1,ed=0;
		for(ll k=0;k<s.size();k++){
			if(bg==-1&&s[k]!=t[k]) bg=k;
			if(s[k]!=t[k]) ed=k;
		}
		cout<<que(s,t,bg,ed)<<'\n';
	}

	return 0;
}
