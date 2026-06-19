#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[N];
int fnd(int a){
	if(fa[a] == a) return fa[a];
	fa[a] = find(fa[a]);
	return fa[a];
}
void mkpir(int a,int b){
	int faa = fnd(a),fab = fnd(b);
	fa[faa] = fab;
	return;
}
struct edge{
	int u,v,c,town;
};
int n,m,k;
int c[K]
vector<edge> edges;
bool cmp(edge x,edge y){
	return x.c < y.c;
}
int kruskal(){
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cout << (1+m) % (1+n) +(n*m) %2
	}
	return 0;
}

