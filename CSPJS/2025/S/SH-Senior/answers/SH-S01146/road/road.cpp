#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+15,maxm=2e6+7;
long long cnt=0,n,m,k,fa[maxn],c[15][maxn];
struct edge{
	long long u,v,w;
}b[maxm];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long find(long long x){
	if(fa[x]==0) return x;
	return find(fa[x]);
}
void merge(long long x,long long y){
	fa[find(x)]=find(y);
	return ;
}
long long kruskal(){
	long long ret=0;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(b[i].u)==find(b[i].v)) continue;
		merge(b[i].u,b[i].v);
		ret+=b[i].w;
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(j==0) continue;
			b[++m].u=n+i;
			b[m].v=j;
			b[m].w=c[i][j];
		}
	}
	cout<<kruskal()<<endl;
}
