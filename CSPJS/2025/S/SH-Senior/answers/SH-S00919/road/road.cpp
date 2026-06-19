#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,fa[N],w,c[N],a[15][N];
long long ans;
struct node{
	int u,v,w;
};
struct cmp{
	bool operator()(node p1,node p2){
		return p1.w>p2.w;
	}
};
priority_queue<node,vector<node>,cmp> q;
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int a1,b1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a1,&b1,&w);
		q.push({a1,b1,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int j=1;j<=n;j++)fa[j]=j;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		int u=x.u,v=x.v,w=x.w;
		int a1=find(u),b1=find(v);
		if(a1==b1)continue;
		fa[b1]=a1;
		ans+=w;
	}
	
	printf("%lld",ans);
	return 0;
} 
