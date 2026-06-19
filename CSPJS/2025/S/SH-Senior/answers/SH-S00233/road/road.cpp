#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005],cnt,ans;
int find(int x){
	if(x!=f[x])
		return f[x]=find(f[x]);
	return x;
}
void uni(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)
		f[y]=x;
}
struct e{
	int u,v,w;
}edge[1000005];
bool cmp(const e &a,const e &b){
	return a.w<b.w;
}
void kruskal(){
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m&&cnt<n;i++)
		if(find(edge[i].u)!=find(edge[i].v)){
			cnt++,ans+=edge[i].w;
			uni(edge[i].u,edge[i].v);
		}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	kruskal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
