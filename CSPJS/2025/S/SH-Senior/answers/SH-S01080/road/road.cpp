#include <bits/stdc++.h>
using namespace std;

int n,m,k,c,x,ans=0;
bool flag;
int vis[1000010],app[1000010];
struct node{
	int u,v,w;
}a[1000010];

bool cmp(node m,node n){
	return m.w<n.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		app[a[i].u]++;
		app[a[i].v]++;
	}
	for (int i=1;i<=k;i++){
		cin>>c;
		for (int j=1;j<=n;j++){
			cin>>x;
		} 
	}
	sort(a+1,a+m+1,cmp);
	flag=false;
	for (int i=1;i<=m;i++){
		if (app[a[i].u]==1 or app[a[i].v]==1){
			flag=true;
			ans+=a[i].w;
			vis[a[i].u]=1;
			vis[a[i].v]=1;
		}
	}
	if (not flag){
		ans+=a[1].w;
		vis[a[1].u]=1;
		vis[a[1].v]=1;
	}
	for (int l=1;l<=100;l++){
		for (int i=1;i<=m;i++){
			if (not vis[a[i].u] and vis[a[i].v] or not vis[a[i].v] and vis[a[i].u]){
				ans+=a[i].w;
				vis[a[i].u]=1;
				vis[a[i].v]=1;
			}
		}	
	}
	
	cout<<ans;
	return 0;
} 
