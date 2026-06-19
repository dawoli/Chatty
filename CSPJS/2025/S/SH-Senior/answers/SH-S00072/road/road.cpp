#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e4+10;
int n,m,k,f[N],c[N],vis[N];
long long ans; 
struct node{
	int u,v,w;
}g[N];
vector<int> a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[m+(i-1)*n+j].u=n+i;
			g[m+(i-1)*n+j].v=j;
			g[m+(i-1)*n+j].w=c[i]+w;
			c[m+(i-1)*n+j]=c[i];
		}
	}
	sort(g+1,g+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		int u=g[i].u,v=g[i].v;
		if(u>n&&!vis[v]){
			merge(u,v);
			ans+=g[i].w;
			//cout<<u<<" "<<v<<" "<<g[i].w<<endl;
			if(vis[u]==1)ans-=c[u];
			//cout<<c[u]<<endl;
			vis[v]=1;
			vis[u]=1;
		}
		else if(find(u)!=find(v)&&u<=n){
			merge(u,v);
			ans+=g[i].w;
			//cout<<u<<" "<<v<<" "<<g[i].w<<endl;
			vis[v]=1;
			vis[u]=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
