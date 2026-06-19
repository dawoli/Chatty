#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
const ll N = 1e5+5,M = 1e6 + 9;
ll T,n,m,L,k,d[N],v[N],a[N],tr[M],c[N],vis[N];
struct node{
	ll l,r;
}p[N];
bool cmp(node X,node Y){return X.r < Y.r;}
ll lb(ll x){return (-x) & x;}
void add(ll x){while(x <= 1e6)++tr[x],x += lb(x);}
ll query(ll x){ll res = 0;while(x)res += tr[x],x -= lb(x);return res;}
ll calc(ll v1,ll v0,ll a){return (v1 * v1 - v0 * v0) / (2 * a); }
bool chk(ll v1,ll v0,ll a){return (v1 * v1 - v0 * v0) % (2 * a) == 0; }
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
//		cout << "Tasks:" << T << endl;
		memset(tr,0,sizeof(tr));
		scanf("%lld%lld%lld%lld",&n,&m,&L,&k);
		rep(i,1,n){
			vis[i] = 0;
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(v[i] <= k && a[i] <= 0)p[i].l = p[i].r = L + 3;
			else if(v[i] > k && a[i] >= 0)p[i].l = d[i],p[i].r = L + 3;
			else{
				if(v[i] > k && a[i] < 0)p[i].l = d[i],p[i].r = min(L + 3,calc(k,v[i],a[i]) + p[i].l - (chk(k,v[i],a[i])));
				else p[i].l = min(L + 3,d[i] + calc(k,v[i],a[i]) + 1),p[i].r = L + 3;
			}
			p[i].l++,p[i].r++;
//			cout << p[i].l << " " << p[i].r << endl;
		}
//		cout << "working1...\n"; 
		rep(i,1,m)scanf("%lld",&c[i]),c[i]++,add(c[i]);
		sort(c + 1,c + m + 1);
		c[m + 1] = 1e8;
		ll ans1 = 0,ans2 = 0;
		sort(p + 1,p + n + 1,cmp);
		rep(i,1,n)if(query(p[i].r) - query(p[i].l - 1))++ans1,vis[i] = 1;
		memset(tr,0,sizeof(tr));
//		cout << "working2...\n"; 
		rep(i,1,n){
			if(query(p[i].r) - query(p[i].l - 1) == 0 && vis[i]){
//				cout << i << endl;
				ll pos = upper_bound(c + 1,c + m + 1,p[i].r) - c - 1;
//				cout << pos << endl;
				add(c[pos]);
				++ans2;
			}
		}
		printf("%lld %lld\n",ans1,m - ans2);
//		cout << "working3...\n"; 
	}
	return 0;
}

