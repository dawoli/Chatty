#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16 + 7;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,K,T,L;
int a[100010];
int aa[100010];
int c[100010],d[20][200010],X[4];
int tmp[800010],grg[800010];
typedef pair<int,int> pii;
vector<pii>val[800010];
int cnt[800010];
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
void pushup(int i,int dep){
	val[i].clear();
	if(!tmp[i]){
		bool flag = 0;
		if(cnt[ls(i)]) flag = 1;
		for(auto v : val[ls(i)]) if(v.first < dep) flag = 1;
		if(!flag){
			cnt[i] = cnt[ls(i)];
			grg[i] = grg[ls(i)];
			for(auto v : val[ls(i)]) val[i].push_back(v);
		}
		else{
			cnt[i] = cnt[ls(i)] + cnt[rs(i)];
			grg[i] = grg[ls(i)] + grg[rs(i)];
			for(auto v : val[ls(i)]){
				if(v.first >= dep) val[i].push_back(v);
				else grg[i] -= v.second;
			}
			for(auto v : val[rs(i)]) if(v.first >= dep) val[i].push_back(v);
		}
	}
	else{
		bool flag = 0;
		if(cnt[rs(i)]) flag = 1;
		for(auto v : val[rs(i)]) if(v.first < dep) flag = 1;
		if(!flag){
			cnt[i] = cnt[rs(i)];
			grg[i] = grg[rs(i)];
			for(auto v : val[rs(i)]) val[i].push_back(v);
		}
		else{
			cnt[i] = cnt[ls(i)] + cnt[rs(i)];
			grg[i] = grg[ls(i)] + grg[rs(i)];
			for(auto v : val[rs(i)]){
				if(v.first >= dep) val[i].push_back(v);
				else grg[i] -= v.second;
			}
			for(auto v : val[ls(i)]) if(v.first >= dep) val[i].push_back(v);
		}
	}
}
void build(int i,int l,int r,int dep){
	int qd = i - (1LL << (K - dep)) + 1;
	if(l == r){
		val[i].clear();
		cnt[i] = 1;
		grg[i] = l;
		return;
	}
	tmp[i] = d[dep][qd];
	int mid = (l + r) >> 1;
	build(ls(i),l,mid,dep - 1),build(rs(i),mid + 1,r,dep - 1);
	pushup(i,dep);
}
void upd(int i,int l,int r,int dep,int pos){
	if(l == r){
		cnt[i] = 0;
		val[i].push_back({a[pos],l});
		grg[i] = l;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) upd(ls(i),l,mid,dep - 1,pos);
	else upd(rs(i),mid + 1,r,dep - 1,pos);
	pushup(i,dep);
}
char s[200010];
int ans[200010],pre[200010];
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n = read(),m = read();
	K = 0;
	while((1LL << K) < n) K++;
	for(int i = 1; i <= n; i++) aa[i] = read();
	for(int i = 1; i <= m; i++) c[i] = read();
	for(int i = 1; i <= K; i++){
		scanf("%s",s + 1);
		int tmp = (1LL << (K - i));
		for(int j = 1; j <= tmp; j++) d[i][j] = s[j] - '0';
	}
	L = (1LL << K);
	pre[K] = 1;
	for(int i = K - 1; i >= 0; i--) pre[i] = pre[i + 1] << 1LL;
	T = read();
	while(T--){
		for(int i = 0; i < 4; i++) X[i] = read();
		for(int i = 1; i <= n; i++) a[i] = aa[i] ^ X[i % 4];
		build(1,1,L,K);
		int oo = 0;
		for(int i = 1; i <= n; i++){
			while((1LL << oo) < i) oo++;
			upd(1,1,L,K,i);
			ans[i] = grg[pre[oo]];
		}
		int res = 0;
		for(int i = 1; i <= m; i++) res ^= (i * ans[c[i]]);
		printf("%lld\n",res);
	}
	return 0;
}
