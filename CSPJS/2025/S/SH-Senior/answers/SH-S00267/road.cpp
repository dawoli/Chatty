#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+11,maxm=1.1e6+1;
struct edge {
	int u,v;
	ll w;
}e[maxm];
int n,m,k,fa[maxn];
int find(int node) {
	if(fa[node]==node) {
		return node;
	}
	return fa[node]=find(fa[node]);
}
ll c[maxn],a[11][maxn],minl=1e18;
bool b[11];
ll generate(int x) {
	ll ans=0;
	sort(e+1,e+m+n*x+1,[](edge a,edge b) {
		return a.w<b.w;
	});
	for(int i=1;i<=m+n*x;i++) {
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) {
			continue;
		}
		fa[u]=v;
		ans+=e[i].w;
	}
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	cout<<e[1].u;
	for(int i=0;i<(1<<k);i++) {
		int cnt=0,p=0,mask=i;
		ll cost=0;
		for(int j=1;j<=k;j++) {
			b[j]=false;
		}
		while(mask) {
			cnt++;
			if(mask&1) {
				b[cnt]=true;
				cost+=c[cnt];
				for(int j=m+p*n+1;j<=m+(p+1)*n;j++) {
					e[j].u=j-m-p*n;
					e[j].v=n+cnt;
					e[j].w=a[cnt][e[i].u];
				}
				p++;	
			}
			mask>>=1;
		}
		minl=min(minl,generate(p)+cost);
		for(int j=m+1;j<=m+n*p;j++) {
			e[j].u=e[j].v=e[j].w=0;
		}
	}
	cout<<minl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
