#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],fa[20005],ans;
struct edge{
	int u,v,w;
}a[8000005];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int find(int x){
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
} 
void merge(int x,int y){
	fa[find(x)] = find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n+k;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		int u1,v1,w1;
		cin >> u1 >> v1 >> w1;
		a[i].u = u1,a[i].v = v1,a[i].w = w1;
	}
	for (int i=1;i<=k;i++){
		cin >> c[i];
		for (int j=1;j<=n;j++){
			int w1;
			cin >> w1;
			a[m+(i-1)*n+j].u = n+i,a[m+(i-1)*n+j].v = j,a[m+(i-1)*n+j].w = w1;
		}
	}
	sort(a+1,a+1+m+k*n,cmp);
	for (int i=1;i<=m+k*n;i++){
		if (find(a[i].u) != find(a[i].v)){
			merge(find(a[i].u),find(a[i].v));
			ans += a[i].w;
		} 
	} 
	cout << ans << endl;
}
