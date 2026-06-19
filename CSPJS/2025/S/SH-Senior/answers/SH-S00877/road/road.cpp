#include<bits/stdc++.h>
using namespace std;
int n,m,k,bcj[100005];
struct Node{
	int u,v,w;
}a[100005];
vector<Node> b[100005];
int find(int x){
	if(bcj[x]==x)return x;
	bcj[x]=find(bcj[x]);
	return find(bcj[x]);
}
int merge(int x,int y){
	if(find(x)==find(y))return 0;
	bcj[x]=y;return 1;
}
void rem(int x){
	int maax,maaxi;
	for(int i=0;i<b[x].size();i++){
		if(b[x][i].w>maax){
			maax=b[x][i].w;maaxi=i;
		}
	}
	b[x].erase(maaxi);
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)bcj[i]=i;
	for(int i=1;i<=n;i++){
		int u,v,w;cin>>u>>v>>w;
		a[i].u=u;a[i].v=v;a[i].w=w;
		if(!merge(u,v)){
			b[find(u)].push_back(a[i]);
			rem(find(u));
		}
	}
	return 0;
}

