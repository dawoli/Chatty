#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const ll base=1331;
const int N = 2e5+10;
int n,q;
struct node{
	string s,t;
	ll st,ed;
	ll cm_hsh;
	ll hsh;
	ll thsh;
	void deal_hash(){
		st=-1;ed=-1;
		hsh=thsh=cm_hsh=0;
		for(int i=0;i<s.size();++i){
			if(s[i]!=t[i]){
				ed=i;
				if(st==-1) st=i;
			}
			hsh=(hsh*base+s[i])%mod;
			thsh=(thsh*base+t[i])%mod;
		}
		for(int i=st;i<=ed;++i)
			cm_hsh=(cm_hsh*base+s[i])%mod;
	} 
}a[N];
map<ll,vector<int> > g;
ll get_hsh(ll l,ll r,string s){
	if(l<0||r>=s.size()) return -1;
	ll ret=0;
	for(int i=l;i<=r;++i){
		ret=(ret*base+s[i])%mod;
	}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i].s>>a[i].t;
		a[i].deal_hash();
		g[a[i].cm_hsh].push_back(i);
//		cout<<a[i].st<<" "<<a[i].ed<<" "<<a[i].cm_hsh<<endl;
	}
	for(int i=1;i<=q;++i){
		node f;
		cin>>f.s>>f.t;
		f.deal_hash();
		int ans=0;
//		cout<<f.st<<" "<<f.ed<<" "<<f.cm_hsh<<endl;
		for(int j=0;j<g[f.cm_hsh].size();++j){
			int k=g[f.cm_hsh][j];
			if(a[k].ed-a[k].st!=f.ed-f.st) continue;
			if(a[k].hsh==get_hsh(f.st-a[k].st,f.ed+a[k].s.size()-1-a[k].ed,f.s))
			if(a[k].thsh==get_hsh(f.st-a[k].st,f.ed+a[k].s.size()-1-a[k].ed,f.t))
				ans++;
		}
//		cout<<"?";
		cout<<ans<<endl;
	}
	return 0;
}
