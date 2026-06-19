#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005,M=1000005,K=11;
int n,m,k,tot,num;
ll ans;
int c[K],a[K][N],fa[N];

struct Edge{
	int u,v,n;
};
bool operator<(const Edge&a,const Edge&b){
	return a.n>b.n;
}
priority_queue<Edge> e;
void add(int x,int y,int z){
	Edge temp;
	temp.u=x;
	temp.v=y;
	temp.n=z;
	e.push(temp);
}
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void kruskal(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int Now=1;
	int cnt=0;
	while(Now<=n-1){
		Edge cur;
		int x;
		int y;
		do{
			cur=e.top();
			e.pop();
			x=find(cur.u);
			y=find(cur.v);
		}while(x==y);
		fa[x]=y;
		ans+=cur.n;
		Now++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int l=j-1;l>=1;l--){
				add(l,j,a[i][j]+a[i][l]);
			}
		}
	}
	
	kruskal();
	cout<<ans;
	return 0;
}
