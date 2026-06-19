#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lb(x) x&(-x)

const int N = 4e5+10, M = 110;
int n, a0[N], d[N], m, b2[N], ls[N], rs[N], fa[N], a[N];
int mxn, cnt, stp[N], nr[N], rx[N], fr[N], mxrp, nowhd, nowk, nowturn, nowr, sum;
bool vis[N];
struct query{
	int pos, h;
}q[N];

bool cmp(query x,query y){
	return x.pos < y.pos;
}

stack<int> sk;

void checkmxrp(){
	while(mxrp >= mxn && d[mxrp] == 0 && a[ls[mxrp]] < rx[mxrp]){
		if(!vis[ls[mxrp]]) break;
		mxrp = rs[mxrp];
	}
}

void add(int x){
	vis[x] = true;
	nowr = nr[x];
	if(x == nowhd) {
		while(!sk.empty()) sk.pop();
		sum = fr[x];
		sk.push(x);
		return;
	}
	if(ls[fa[x]] == x){
		if(d[fa[x]] == 0 && a[x] >= rx[fa[x]]){
			a[fa[x]] = a[x];
			fr[fa[x]] = fr[x];
			add(fa[x]);
			return;
		}
		if(d[fa[x]] == 0 && a[x] < rx[fa[x]]){
			return;
		}
		if(fa[x] == nowhd && d[fa[x]] == 1){
			sum += fr[x];
			sk.push(x);
			return;
		}
		checkmxrp();
		if(a[x] >= rx[mxrp]) sum += fr[x], sk.push(x);
		return;
	}
	if(rs[fa[x]] == x){
		if(d[fa[x]] == 0 && a[ls[fa[x]]] < rx[fa[x]]){
			a[fa[x]] = a[x];
			fr[fa[x]] = fr[x];
			add(fa[x]);
			return;
		}
		if(d[fa[x]] == 1 && a[x] >= rx[fa[x]]){
			a[fa[x]] = a[x];
			fr[fa[x]] = fr[x];
			if(!sk.empty() && sk.top() == fa[ls[x]]) {
				sum -= fr[sk.top()];
				sk.pop();
			}
			add(fa[x]);
			return;
		}
		if(d[fa[x]] == 1 && a[x] < rx[fa[x]]){
			a[fa[x]] = a[ls[fa[x]]];
			fr[fa[x]] = fr[ls[fa[x]]];
			if(!sk.empty() && sk.top() == fa[ls[x]]){
				sum -= fr[sk.top()];
				sk.pop();
			}
			add(fa[x]);
			return;
		}
		if(d[fa[x]] == 0 && a[ls[fa[x]]] >= rx[fa[x]]){
			return;
		}
	}
}

signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a0[i];
	for(int i = 1; i <= m; i++){
		cin >> q[i].pos;
		q[i].h = i;
	}
	int k;
	for(k = 1; k <= n; k<<=1);
	cnt = k;
	mxn = k;
	stp[0] = 0;
	for(int i = 1; i <= k; i++) nr[i] = i, rx[i] = 0, fr[i] = i;
	int cntr = 0;
	for(k>>=1;k;k>>=1){
		stp[++cntr] = cnt;
		string s;
		cin >> s;
		for(int j = 1; j <= k; j++){
			d[++cnt] = s[j-1]-'0';
			ls[cnt] = stp[cntr-1] + j*2-1;
			rs[cnt] = stp[cntr-1] + j*2;
			fa[ls[cnt]] = cnt;
			fa[rs[cnt]] = cnt;
			nr[cnt] = nr[rs[cnt]];
			rx[cnt] = cntr;
		}
	}
	sort(q+1,q+m+1,cmp);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for(int i = 1; i < N; i++) vis[i] = 0;
		for(int j = 0; j <= n; j += 4){
			a[j] = a0[j]^x[0];
			a[j+1] = a0[j+1]^x[1];
			a[j+2] = a0[j+2]^x[2];
			a[j+3] = a0[j+3]^x[3];
		}
		nowk = 1;
		nowturn = 1;
		nowhd = 1;
		mxrp = 1;
		nowr = 0;
		sum = 0;
		int res = 0, rp = 1;
		for(int j = 1; j <= m; j++){
			while(nowr < q[j].pos){
				if(nowr+1 > nowk) {
					sum = 0;
					while(!sk.empty()) sk.pop(); 
					nowk <<= 1, nowturn++, nowhd = fa[nowhd], mxrp = nowhd;
					add(ls[nowhd]);
				}
				add(++nowr);
			}
			int adsum = (nowr+1+nowk)*(nowk-nowr)/2;
			res ^= ((sum+max(0ll,adsum))*q[j].h);
		}
		cout << res << endl;
	}
}
