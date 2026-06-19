#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[20009];
int root(int x){
	if(fa[x]==x)return x;
	fa[x]=root(fa[x]);
	return fa[x];
}
struct Node{
	int u,v,w;
}a[1200000];
bool cmp(Node a1,Node a2){
	return a1.w<a2.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[m+(i-1)*n+j].w;
			a[m+(i-1)*n+j].u=n+i;
			a[m+(i-1)*n+j].v=j;
		}
	}
	
	
	
	sort(a+1,a+m+n*k+1,cmp);
	long long ans=0;
	int i=0,cnt=0;
	while(cnt<n+k-1){
		i++;
		if(root(a[i].u)==root(a[i].v)){
			continue;
		}
		fa[root(a[i].u)]=root(a[i].v);
		cnt++;
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
