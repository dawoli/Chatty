#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,k,f[10005],cnt,p[15];
long long ans;
struct nod{
	int u,v;
	long long w;
}e[1000005];
bool cmp(nod x,nod y){
	return x.w < y.w;
};
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1;i <= m;i++){
		if(find(e[i].u) != find(e[i].v)){
			f[find(e[i].u)] = find(e[i].v);
			ans += e[i].w;
			cnt++;
		}
		if(cnt == n - 1) break;
	}
	cout << ans;
	return 0;
}
