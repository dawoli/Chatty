#include<bits/stdc++.h>
using namespace std;
#define N 200009
// #define int long long
int n,m,LOG,a[N],a_[N],c[N],sz[20],seed[4];
bool g[22][N];
struct node{
	int l,r,dep,idx;
	set<int> s;
} tr[N * 4];
set<int>::iterator it1,it2;
void input(){
	scanf("%d %d",&n,&m);
	LOG = floor(log2(n - 1)) + 1;
	for(int i = 1;i <= n;i++) scanf("%d",&a_[i]);
	for(int i = 1;i <= m;i++) scanf("%d",&c[i]);
	for(int i = 1;i <= LOG;i++){
		sz[i] = (1 << (LOG - i));
		for(int j = 1;j <= sz[i];j++){
			char c;
			cin>>c;
			g[i][j] = c - '0';
		}
	}
}
void generate(){
	for(int i = 1;i <= n;i++)
		a[i] = (a_[i] ^ seed[i % 4]);
}
void merge(int u,int lim){
	tr[u].l = tr[u * 2].l; tr[u].r = tr[u * 2 + 1].r;
	tr[u].dep = tr[u * 2].dep + 1; tr[u].idx = tr[u * 2 + 1].idx / 2;
	tr[u].s.clear();
	int d = tr[u].dep,i = tr[u].idx;
	
	for(it1 = tr[u * 2].s.begin();it1 != tr[u * 2].s.end();it1++)
		for(it2 = tr[u * 2 + 1].s.begin();it2 != tr[u * 2 + 1].s.end();it2++){
			int x = *it1,y = *it2;
			if(x < y) swap(x,y);
			if(x <= lim){
				if((a[x] >= d && g[d][i] == 1) || (a[y] < d && g[d][i] == 0)) tr[u].s.insert(x);
				else tr[u].s.insert(y);
			}else if(y > lim){
				tr[u].s.insert(x);
				tr[u].s.insert(y);
			}else{
				if(a[y] < d || g[d][i] == 1) tr[u].s.insert(x);
				if(a[y] >= d || g[d][i] == 1) tr[u].s.insert(y);
			}
		}
	tr[u * 2].s.clear();
	tr[u * 2 + 1].s.clear();
}
void build(int u,int l,int r,int lim){
	if(l == r){
		tr[u].l = l; tr[u].r = r;
		tr[u].dep = 0; tr[u].idx = l;
		tr[u].s.clear();
		tr[u].s.insert(l);
		return;
	}
	int mid = (l + r) / 2;
	build(u * 2,l,mid,lim);
	build(u * 2 + 1,mid + 1,r,lim);
	merge(u,lim);
}
void solve(){
	long long ans = 0;
	for(int i = 1;i <= m;i++){
		if(c[i] == 1){ ans ^= i; continue; }
		build(1,1,(1 << ((int)log2(c[i] - 1) + 1)),c[i]);
		long long res = 0;
		for(it1 = tr[1].s.begin();it1 != tr[1].s.end();it1++)
			res += *it1;
		ans ^= (1ll * i * res);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	input();
	int T;
	cin>>T;
	while(T--){
		for(int i = 0;i < 4;i++) cin>>seed[i];
		generate();
		solve();
	}
	return 0;
}
