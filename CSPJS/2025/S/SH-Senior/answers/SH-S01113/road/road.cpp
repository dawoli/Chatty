#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+5;
const int M=15*1e6+5; 
int n,m,k,fa[N];
long long c[11];
long long a[11][N];
struct edge{
	int u,v;
	long long w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fiind(int x){
	if(x==fa[x]) return x;
	return fa[x]=fiind(fa[x]);
}
void Kru(){
	long long sum=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		int fx=fiind(x),fy=fiind(y);
		if(fx==fy) continue;
		sum+=e[i].w;
		fa[fx]=fy;
	}
	cout<<sum;
}
void addedge(int x,int y,long long z){
	m++;
	e[m].u=x;
	e[m].v=y;
	e[m].w=z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				addedge(j,k,1LL*(a[i][j]+a[i][k]+c[i]));
			
	}
	Kru();
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
