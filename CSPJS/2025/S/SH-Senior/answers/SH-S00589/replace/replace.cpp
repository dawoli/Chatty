#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
#include<queue>
#include<cstring>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 200010, M = 5000010;
int n, q, id[N][2];
string s[N][2], t[N][2];

namespace ACAM{
	struct edge {int to, nxt;} e[M];
	int h[M], fail[M], l[M], r[M], ch[M][26], tot, cd, ce;
	int insert(const string &s){
		int u = 0;
		for(const char &c : s){
			int t = c-'a';
			if(!ch[u][t]) ch[u][t] = ++tot;
			u = ch[u][t];
		}
		return u;
	}
	void dfs(int x){
		l[x] = ++cd;
		for(int y = h[x]; y; y = e[y].nxt) dfs(e[y].to);
		r[x] = cd;
	}
	void build(){
		queue<int> q;
		rep(i, 0, 25) if(ch[0][i]) q.push(ch[0][i]);
		while(!q.empty()){
			int x = q.front(); q.pop();
			e[++ce] = {x, h[fail[x]]}; h[fail[x]] = ce;
			rep(i, 0, 25)
				if(!ch[x][i]) ch[x][i] = ch[fail[x]][i];
				else fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
		}
		dfs(0);
	}
};

struct BIT{
	int t[M];
	void update(int x, int val){
		// fprintf(stderr, "BIT: update: %d %d\n", x, val);
		for(; x <= ACAM::cd; x += x & -x) t[x] += val;
	}
	void update(int l, int r, int val) {update(l, val), update(r+1, -val);}
	int query(int x){
		int ret = 0;
		for(; x; x ^= x & -x) ret += t[x];
		return ret;
	}
};
BIT bit;

int p[N], cq;
struct que {int l1, l2, k, id;} v[M];
int ce;
struct node {int x, l, r, op;} e[N*3];
ll ans[N];

void solve(){
	sort(e+1, e+ce+1, [&](const node &x, const node &y) {return x.x^y.x ? x.x<y.x : x.op&&!y.op;});
	rep(i, 1, ce){
		// fprintf(stderr, "%d %d %d %d\n", e[i].x, e[i].l, e[i].r, e[i].op);
		if(e[i].op) bit.update(e[i].l, e[i].r, e[i].op);
		else ans[e[i].r] += bit.query(e[i].l);
	}
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n)
		cin >> s[i][0] >> s[i][1],
		id[i][0] = ACAM::insert(s[i][0]),
		id[i][1] = ACAM::insert(s[i][1]);
	ACAM::build();
	rep(i, 1, n) p[i] = i;
	sort(p+1, p+n+1, [&](int x, int y) {return s[x][0].length() > s[y][0].length();});
	rep(i, 1, q){
		cin >> t[i][0] >> t[i][1];
		if(t[i][0].length() != t[i][1].length()) continue;
		int t1 = 0, t2 = (int)t[i][0].length()-1;
		while(t1 < (int)t[i][0].length() && t[i][0][t1] == t[i][1][t1]) t1++;
		while(t2 >= 0 && t[i][0][t2] == t[i][1][t2]) t2--;
		assert(t1 <= t2);
		int u1 = 0, u2 = 0;
		rep(j, 0, (int)t[i][0].length()-1){
			u1 = ACAM::ch[u1][t[i][0][j]-'a'];
			u2 = ACAM::ch[u2][t[i][1][j]-'a'];
			if(j >= t2) v[++cq] = {ACAM::l[u1], ACAM::l[u2], j-t1+1, i};
		}
	}
	sort(v+1, v+cq+1, [&](const que &x, const que &y) {return x.k < y.k;});
	rep(i, 1, cq){
		ce = 0;
		int j = i;
		while(j <= cq && v[j].k == v[i].k){
			e[++ce] = {v[j].l1, v[j].l2, v[j].id, 0};
			j++;
		}
		rep(k, 1, n){
			if((int)s[p[k]][0].length() < v[i].k) break;
			e[++ce] = {ACAM::l[id[p[k]][0]], ACAM::l[id[p[k]][1]], ACAM::r[id[p[k]][1]], 1};
			e[++ce] = {ACAM::r[id[p[k]][0]]+1, ACAM::l[id[p[k]][1]], ACAM::r[id[p[k]][1]], -1};
		}
		solve();
		i = j-1;
	}
	rep(i, 1, q) cout << ans[i] << '\n';
	return 0;
}

// g++ -std=c++14 -O2 -Wall -Wextra -Wno-unused-result -fsanitize=undefined replace.cpp -o replace
// cp replace1.in replace.in && time ./replace && diff replace.out replace1.ans -b