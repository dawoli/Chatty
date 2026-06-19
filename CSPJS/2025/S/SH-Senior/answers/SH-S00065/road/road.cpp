#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e4,M=2e7;
int n,m,k,cnt,c,a[N+1],fa[N+1];
long long ans;
struct edge{
	int u,v,w;
}e[M];
vector<int>g[N+1];
bool cmp(edge a,edge b){
	return a.w<b.w; 
}
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w,
		g[e[cnt].u].push_back(cnt),g[e[cnt].v].push_back(cnt),
		cnt++;
	for(int i=0;i<k;i++){
		cin>>c;
		int u=0;
		for(int v=1;v<=n;v++){
			cin>>a[v];
			if(!c&&!a[v])u=v;
		}
		for(int j=0;j<n;j++)
			e[cnt].u=u,e[cnt].v=j,e[cnt].w=a[j],cnt++;
	}
	sort(e,e+cnt,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0,m=n;m>1;i++){
		int u=e[i].u,v=e[i].v;
		u=find(u),v=find(v);
		if(u!=v)
			fa[u]=v,ans+=e[i].w,m--;
	}
	cout<<ans;
	return 0;
} 
