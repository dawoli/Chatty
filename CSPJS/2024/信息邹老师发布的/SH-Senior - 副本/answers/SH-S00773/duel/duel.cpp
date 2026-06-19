#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define sizc(x) ((x).size())
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N = 1e5+5;

int n,a[N]; 

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	rep(i,1,n){
		int x;cin>>x;
		++a[x];
	}
	int ans=0;
	rep(i,1,1e5){
		ans-=min(ans,a[i]);
		ans+=a[i];
	}
	cout<<ans<<'\n';
} 
