#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
struct node{
	int from,to,val;
}G[2000006];
int fa[10005];
int find(int idx){
	if(fa[idx]==idx)
		return idx;
	else{
		int id=find(fa[idx]);
		fa[idx]=id;
		return id;
	}
		
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		node a;
		a.from=x;
		a.to=y;
		a.val=z;
		G[i]=a;
	}
	int cnt=0;
	unsigned long long ans=0;
	sort(G+1,G+1+m,cmp);
	for(int i=1;i<=m;i++){
		int na=G[i].to;
		int nb=G[i].from;
		int nna=find(na);
		int nnb=find(nb);
		if(nna!=nnb){
			ans+=G[i].val;
			fa[nnb]=nna;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	cout<<ans<<endl;
}
