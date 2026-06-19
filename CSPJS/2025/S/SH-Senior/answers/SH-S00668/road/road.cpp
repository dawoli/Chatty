#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	const operator < (const Edge o){
		return w < o.w;
	}
}es[1000009];
int p[10009];
int find(int x){
	if(p[x] != x){
		return p[x] = find(p[x]);
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i < n;i++){
		p[i] = i;
	}
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		es[i].u = u;
		es[i].v = v;
		es[i].w = w;
	}
	sort(es,es + m);
	int c[k],a[k][n];
	for(int i = 0;i < k;i++){
		cin>>c[i];
		for(int j = 0;j < n;j++){
			cin>>a[i][j];
		}
	}
	int cnt = 0,sum = 0;
	for(int i = 0;i < m;i++){
		int px = find(es[i].u),py = find(es[i].v);
		if(px != py){
			cnt++;
			sum += es[i].w;
			p[es[i].v] = es[i].u;
		}
		if(cnt == m){
			break;
		}
	}
	cout<<sum;
	return 0;
}
