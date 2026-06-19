#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,w;
}a[2000005];
int n,m,k,f[15],fa[2000005],flag[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			cnt++;
			a[cnt].u=i+n;
			a[cnt].v=j;
			a[cnt].w=y;
		}
	}
	for(int i=1;i<=cnt;i++){
		fa[i]=i;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(a[i].u)==find(a[i].v)) continue;
		ans+=a[i].w;
		fa[find(a[i].u)]=find(a[i].v);
		if(a[i].u>n){
			flag[a[i].u-n]++;
			f[a[i].u-n]=a[i].w;
		}
		if(a[i].u>n){
			flag[a[i].u-n]++;
			f[a[i].u-n]=a[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		if(flag[i]==1) ans-=f[i];
	}
	cout<<ans;
}

