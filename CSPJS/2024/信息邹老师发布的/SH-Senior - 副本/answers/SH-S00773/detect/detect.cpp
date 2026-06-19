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

int n,m;
ll L,V;
ll d[N],v[N],a[N],p[N];

ll get(ll v,ll a,ll d){
	return v+2*a*d;
}

void solve(){
	cin>>n>>m>>L>>V;V*=V;
	rep(i,1,n)cin>>d[i]>>v[i]>>a[i],v[i]*=v[i];
	rep(i,1,m)cin>>p[i];
	vector<pair<int,int>> seg;
	rep(i,1,n){
		if(a[i]>=0){
			if(d[i]>p[m]||get(v[i],a[i],p[m]-d[i])<=V)continue;
			int pos=lower_bound(p+1,p+m+1,d[i])-p;
			int l=pos,r=m;
			while(l<r){
				int mid=l+r>>1;
				if(get(v[i],a[i],p[mid]-d[i])>V)r=mid;
				else l=mid+1;
			}
			seg.emplace_back(l,m);
		}
		else{
			int pos=lower_bound(p+1,p+m+1,d[i])-p;
			if(pos>m||get(v[i],a[i],p[pos]-d[i])<=V)continue;
			int l=pos,r=m;
			while(l<r){
				int mid=l+r+1>>1;
				if(get(v[i],a[i],p[mid]-d[i])>V)l=mid;
				else r=mid-1;
			}
			seg.emplace_back(pos,l);
		}
	}
	cout<<seg.size()<<' ';
	sort(allc(seg),greater<pair<int,int>>());
	int lst=m+1,ans=0;
	for(auto p:seg)if(lst>p.sec)++ans,lst=p.fir;
	cout<<m-ans<<'\n';
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;cin>>T;
	while(T--)solve();
} 
