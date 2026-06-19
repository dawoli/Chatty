#include<bits/stdc++.h>
using namespace std;
const int KS=1e6+20;
int n,m,k;
int fa[KS];
int find(int x) {
	if(x==fa[x]) {
		return x;
	}
	return fa[x]=find(fa[x]);
}
struct N {
	int x,y,z;
	bool operator < (const N &o) const {
		return z<o.z;
	}
};
N a[KS];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n+k; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+m);
	long long ans=0;
	for(int i=1; i<=m; i++) {
		int x=find(a[i].x);
		int y=find(a[i].y);
		if(x!=y) {
			fa[x]=y;
			ans+=a[i].z;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
