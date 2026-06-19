#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,u[10005],ans;

int find(int x) {
	if (x==u[x]) return x;
	u[x]=find(u[x]);
	return u[x];
}

void add(int f,int x) {
	u[find(x)]=u[f];
}

struct edge {
	int u,v,w;
}e[1000005];

bool cmp(edge x,edge y) {
	return x.w<y.w;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++) {
		u[i]=i;
	}
	for (int i=1;i<=m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[i]=(edge){u,v,w};
	}
	for (int i=1;i<=k;i++) {
		int c;
		cin >> c;
		for (int j=1;j<=n;j++) {
			int a;
			cin >> a;
		}
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++) {
		if (find(e[i].u)==find(e[i].v)) {
			continue;
		}
		ans+=e[i].w;
		add(e[i].u,e[i].v);
	}
	cout << ans;
}

//此版本为普通最小生成树 
