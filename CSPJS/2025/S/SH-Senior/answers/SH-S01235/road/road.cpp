#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,fa[10005],c,cc[100005];
struct node{
	int u,v,w;
}e[1000006];
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x] = find(fa[x]);
}
void merge(int x, int y){
	if(find(x)==find(y))return ;
	fa[find(x)] = find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k==0){
		for(int i = 1; i <= n; i++)fa[i] = i;
		for(int i = 1; i <= m; i++){
			cin >> e[i].u >> e[i].v >> e[i].w;
		}
		sort(e+1,e+m+1,cmp);
		long long ans = 0;
		
		for(int i = 1; i <= m; i++){
			if(find(e[i].u)!=find(e[i].v)){
				merge(e[i].u,e[i].v);
				ans+=e[i].w;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int l = m;
	for(int i = 1; i <= k; i++){
		cin >> c;
		for(int i = 1; i <= n; i++){
			cin >> cc[i];
		}
		for(int i = 1; i <= n; i++){
			if(cc[i]==0){
				for(int j = 1; j <= n; j++){
					if(j==i)continue;
					e[++l].u = i;
					e[l].v = j;
					e[l].w = cc[j];
				}
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	long long ans = 0;	
	for(int i = 1; i <= m; i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 3 0 1 2 1 1 3 1 2 3 3
