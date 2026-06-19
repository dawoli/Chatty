#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=11000;
int fa[N];
void init(){
	for(int i=1;i<N;i++)fa[i]=i;
}
int find(int a){
	if(fa[a]==a)return a;
	fa[a]=find(fa[a]);
	return fa[a];
}
void merge(int a,int b){
	fa[find(a)]=find(b);
}
int n,m,k;
struct edge{
	int a,b,w;
}edges[1100000];
vector<edge>uedges;
struct farm{
	int c,a[11000];
}farms[20];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int kelusikaer(int c){
	init();
	int ans=c;
	sort(uedges.begin(),uedges.end(),cmp);
	for(auto now:uedges){
		int ga=find(now.a),gb=find(now.b);
		if(ga==gb)continue;
		fa[ga]=gb;
		ans+=now.w;
	}
	return ans;
}
int vis[20],ans=LLONG_MAX;
void dfs(int pos){
	if(pos==k+1){
		uedges.clear();
		for(int i=1;i<=n;i++)uedges.push_back(edges[i]);
		int temp=0,kkk=0;
		for(int i=1;i<=k;i++){
			if(vis[i]==1){
				kkk++;
				temp+=farms[i].c;
				for(int j=1;j<=n;j++){
					edge newedge;
					newedge.a=j,newedge.b=n+kkk,newedge.w=farms[i].a[j];
					uedges.push_back(newedge);
				}
			}
		}
		ans=min(ans,kelusikaer(temp));
		return;
	}
	vis[pos]=1;
	dfs(pos+1);
	vis[pos]=0;
	dfs(pos+1);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>edges[i].a>>edges[i].b>>edges[i].w;
	for(int i=1;i<=k;i++){
		cin>>farms[i].c;
		for(int j=1;j<=n;j++)cin>>farms[i].a[j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
