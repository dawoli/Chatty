#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
int n,m,k,u,v,w,idx,ans,c[N],cnt;
struct node{
	int u,v,w;
} edge[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	sync();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		edge[i+m].u=edge[i].u,edge[i+m].v=edge[i].v,edge[i+m].w=edge[i].w;
		f[i]=i;
	}
	sort(edge+1,edge+n+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(edge[i].u),y=find(edge[i].v);
		if(x!=y){
			f[y]=x;
			idx++;
			ans+=edge[i].w;
		}
		if(idx==n-1) break;
	}
	cout<<ans;
	return 0;
}

