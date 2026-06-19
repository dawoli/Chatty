#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long g[10005][10005];
long long ne[15][10];
long long cnt[10005];
int fa[10005];
long long ans;


int find(int x){
	if(fa[x]=x) return x;
	else return find(fa[x]);
}

void merge(int x,int y){
	int fa_x = find(x);
	int fa_y = find(y);
	cnt[fa_y] += cnt[fa_x];
	fa[fa_x] = fa_y;
}

struct node{
	int u,v,w;
}g_m[1000005];

bool cmp(node x,node y){
	return x.w<y.w;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cnt[i] = 1;
		fa[i] = i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j] = 0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u][v] = min(g[u][v],w);
		g[v][u] = min(g[v][u],w);
	}
	for(int i=1;i<=k;i++){
		cin>>ne[i][1];
		for(int j=2;j<=n+1;j++){
			cin>>ne[i][j];
		}
	}	
	for(int i=1;i<=k;i++){
		for(int j=2;j<=n+1;j++){
			for(int d=j+1;d<=n+1;d++){
				if(ne[i][j]+ne[i][d]+ne[i][1]<g[j-1][d-1]){
					g[j-1][d-1] = ne[i][j]+ne[i][d]+ne[i][1];
				}
			}
		}
	}
	int tot = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int a,b,c;
			a=i;b=j;c=g[i][j];
			g_m[++tot] = {a,b,c};
		}
	}
	sort(g_m+1,g_m+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int u_n = g_m[i].u;
		int v_n = g_m[i].v;
		int w_n = g_m[i].w;
		if(find(u_n)==find(v_n)) continue;
		ans += w_n;
		merge(u_n,v_n);
		if(cnt[v_n]==n){
			break;
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
