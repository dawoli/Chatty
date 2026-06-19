#include <bits/stdc++.h>
using namespace std;
int n, m, ap[100005], c[100005], t, x[5], a[100005], tmp[200005];
int pl[100005], ans, d[20][100005], twh, K;
void dfs2(int ls, int i, int p, int ttt);
void dfs(int ls, int p, int ttt){
	if(p == 1){
		if(!tmp[pl[1]+n]) ans += abs(pl[1]);
		tmp[pl[1]+n] = 1;
		return;
	}
	dfs2(ls, 1, p, ttt);
}
void dfs2(int ls, int i, int p, int ttt){
	if(i > p){
		dfs(ls+1, p/2, ttt);
		return;
	}
	int dls = d[ls][i/2+1];
	int lz = i+dls, ot = i+1-dls;
	int plz = pl[lz], pot = pl[ot];
	if(plz < 0){
		pl[i/2+1] = plz;
		dfs2(ls, i+2, p, ttt);
		pl[i/2+1] = pot;
		dfs2(ls, i+2, p, ttt);
	}else{
		if(a[plz] < ls){
			pl[i/2+1] = pot;
			dfs2(ls, i+2, p, ttt);
		}else{
			pl[i/2+1] = plz;
			dfs2(ls, i+2, p, ttt);
		}
	}
}
struct str{int a, b;};
str get2k(int wt){
	int i = 1, tmp = 1;
	while(i < wt) i *= 2, tmp++;
	return {i, tmp};
}
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>ap[i];
	for(int i = 1;i <= m;i++) cin>>c[i];
	K = get2k(n).b;
	for(int i = 1;i < K;i++){
		for(int j = 1;j <= (1<<(K-i-1));j++){
			scanf("%1d", &d[i][j]);
		}
	}
	cin>>t;
	while(t--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i = 1;i <= n;i++) a[i] = (ap[i]^x[i%4]);
		int al = 0;
		for(int ti = 1;ti <= m;ti++){
			for(int i = 1;i <= c[ti];i++) pl[i] = i;
			int tk = get2k(c[ti]).a, ttt = get2k(c[ti]).b;
			for(int i = c[ti]+1;i <= tk;i++) pl[i] = -i;
			ans = 0;
			memset(tmp, 0, sizeof(tmp));
			dfs(1, tk, ttt);
			if(ti == 1) al = ans*ti;
			else al ^= ans*ti;
		}
		cout<<al<<endl;
	}
	return 0;
}
