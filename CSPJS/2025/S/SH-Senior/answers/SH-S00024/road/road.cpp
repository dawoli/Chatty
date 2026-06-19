#include <bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}a[1000110];
long long fa[1000010];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(long long x,long long y){
	fa[find(x)] = find(y);
}
bool cmp(node x,node y){
	if(x.w == y.w && x.u == y.u) return x.v < y.v;
	else if(x.w == y.w) return x.u < y.u;
	return x.w < y.w;
}
long long minn = 0x3f,sum,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		minn = min(minn,a[i].w); 
	}
	sort(a+1,a+m+1,cmp);
	for(int i = 1;i <= m;i++){
		if(find(a[i].u) != find(a[i].v)){
			merge(a[i].u,a[i].v);
			sum += a[i].w;
		}
	}
	cout << sum;
	return 0;
}
