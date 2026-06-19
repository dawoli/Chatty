#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[17],a[17][10010];
int fa[500010];
int nn;
struct node{
	int u,v,w;
};
node mp[3000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void merge(int x,int y){
	//if(find(x)!=find(y)){
	fa[y]=find(fa[x]);
	//}
}
long long kruscal(){
	long long cntk=0;
	for(int i=1;i<=m;i++){
		long long u=mp[i].u,v=mp[i].v,w=mp[i].w;
//		cout<<u<<" "<<v<<"    ";
//		cout<<fa[u]<<" "<<fa[v]<<"    ";
//		cout<<find(u)<<" "<<find(v)<<endl;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
//			cout<<u<<" "<<v<<"    ";
//			cout<<fu<<" "<<fv<<endl;
			if(fu>fv){
				swap(u,v);
			}
			merge(u,v);
			cntk+=w;
		}
	}
	return cntk;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//edge[u][v]=edge[v][u]=w;
		mp[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]==0){
			nn+=1;
			for(int j=1;j<=n;j++){
				mp[++m]={n+nn,j,a[i][j]};
				fa[n+nn]=n+nn;
			}
		}
	}
	sort(mp+1,mp+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<mp[i].u<<" "<<mp[i].v<<" "<<mp[i].w<<endl;
//	}
	cout<<kruscal()<<endl;
	return 0;
}
/*
4 6 0
1 4 6
2 3 7
4 2 5
4 3 4
1 3 2
1 2 9

*/

