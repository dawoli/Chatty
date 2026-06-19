#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+25,M=1e6+1e5+5;

int n,m,k;
//vector<int> g[M],w[M];
int c[N],a[15][N];
int f[N];
ll ans;
bool flagA=true;

int find(int x){
	if(f[x]!=x)return find(f[x]);
	return x;
}

void merge(int x,int y){
	if(find(x)!=find(y))f[find(x)]=find(y);
}

struct node{
	int u,v,w;
}g[M];

bool cmp(node x,node y){
	if(x.w!=y.w)return x.w<y.w;
	return x.u<y.u;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)flagA=false;
		for(int j=1;j<=n;j++){
			g[++m].u=n+i;
			g[m].v=j;
			scanf("%d",&g[m].w);
			
		}
	}
	if(flagA){
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=g[i].u;
			int y=g[i].v;
			if(find(x)!=find(y)){
				ans+=g[i].w;
				merge(x,y);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}
