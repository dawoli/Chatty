#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10010][10010];
long long ans;
bool f[10010];
struct S{
	int a,p[10010];
} c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
		ans+=z;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i].a;
		for(int j=1;j<=n;++j)
			cin>>c[i].p[j];
	}
	cout<<ans;
	return 0;
}
