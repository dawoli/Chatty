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

constexpr int N = 2e5+5, M = 1e6+5;

int n,m=1e6,a[N];

ll lm[M];

void solve(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	ll tag=0;
	lm[0]=0;rep(i,1,m)lm[i]=-1e18;
	ll am=0;
	rep(i,2,n){
		ll t=max(am,lm[a[i]]+a[i])+tag;
		if(a[i]==a[i-1])tag+=a[i];
		am=max(am,t-tag);
		lm[a[i-1]]=max(lm[a[i-1]],t-tag);
	}
	cout<<*max_element(lm,lm+m+1)+tag<<'\n';
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;cin>>T;
	while(T--)solve();
} 
