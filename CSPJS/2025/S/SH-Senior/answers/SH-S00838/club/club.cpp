#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define fir first
#define sec second

constexpr int N = 1e5+5;

int n;
int ch[N];
ll d[N];

void solve(){
	cin>>n;
	ll ans=0;
	rep(i,1,n){
		array<ll,3> a{};
		for(auto &j:a)cin>>j;
		ch[i]=max_element(a.begin(),a.end())-a.begin();
		ans+=a[ch[i]];
		ll tmx=0;repn(j,3)if(j!=ch[i])tmx=max(tmx,a[j]);
		d[i]=a[ch[i]]-tmx; 
	}
	repn(x,3)if(count(ch+1,ch+n+1,x)>n/2){
		vector<ll> vc;
		rep(i,1,n)if(ch[i]==x)vc.push_back(d[i]);
		sort(vc.begin(),vc.end(),greater<ll>());
		while(vc.size()>n/2){
			ans-=vc.back();
			vc.pop_back();
		}
		break;
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;cin>>T;
	while(T--)solve();
} 
