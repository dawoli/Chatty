#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=1e4+10;

struct node{
	int u,v,w;
} a[N];

int fa[N];

int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}

bool cmp(node x,node y){
	return x.w<y.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=a[i].u,y=a[i].v,ww=a[i].w;
		if(find(x)!=find(y)){
			fa[x]=find(y);
			ans+=ww; 
		}
	}
	cout<<ans;
}
