#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+3,maxm=1e6+3;
struct edge{
	int u,v,w;
}e[maxm],e2[maxm+maxn*10];
ll ans=4e18;
int n,m,k,fa[maxn],a[13][maxn];
bool have[13];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fy]=fx;
}
void kruskal(int num,int ext){
	sort(e2+1,e2+num+1,cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	ll sum=0;
	for(int i=1;i<=num;i++){
		if(find(e2[i].u)!=find(e2[i].v)){
			sum+=e2[i].w;
			merge(e2[i].u,e2[i].v);
		}
	}
	ans=min(ans,sum+ext);
}
void dfs(int c,int sum){
	if(c==k+1){
		for(int i=1;i<=m;i++){
			e2[i]=e[i];
		}
		int tot=m;
		for(int i=1;i<=k;i++){
			if(!have[i])continue;
			for(int j=1;j<=n;j++){
				e2[++tot]={n+1,j,a[i][j]};
			}
		}
		kruskal(tot,sum);
		return;
	}
	have[c]=true;
	dfs(c+1,sum+a[c][0]);
	have[c]=false;
	dfs(c+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	bool flag=false;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		bool tmp=true;
		cin>>a[i][0];
		if(a[i][0])tmp=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j])tmp=false;
		}
		flag|=tmp;
	}
	if(flag){
		cout<<"0";
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
