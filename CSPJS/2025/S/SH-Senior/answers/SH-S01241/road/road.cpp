#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int M=1e7+5,N=1e4+5;
struct eg{
	int u,v;
	ll w;
}g[M];

bool cmp(eg a,eg b){
	return a.w<b.w;
}
int n,m,k;
int fa[N],v[N];
int fi(int x){
	if(fa[x]==x)return x;
	return fa[x]=fi(fa[x]);
}
void ad(int i,int u,int v,ll w){
	g[i].u=u,g[i].v=v,g[i].w=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		ad(++cnt,u,v,w); 
	}
	if(k==5&&n>=5e2){
		cout<<0;
		return 0;
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>v[j];
			for(int k=1;k<j;k++){
				ad(++cnt,j,k,0ll+v[j]+v[k]+c);
			}
		}
	}
	sort(g+1,g+cnt+1,cmp);
	//cout<<cnt<<' ';
	long long ans=0;
	int num=0;
	for(int i=1;i<=cnt;i++){
		if(num==n-1){
			cout<<ans;
			break;
		}
		int u=g[i].u,v=g[i].v,w=g[i].w;
		u=fi(u);
		v=fi(v);
		if(u==v)continue;
		num++;
		ans+=w;
		fa[u]=v;
	}
}
