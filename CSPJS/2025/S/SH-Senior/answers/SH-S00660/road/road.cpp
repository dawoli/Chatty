#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[20],a[20][10010],fa[10010],ct,cnt,bc,ans,res=LLONG_MAX;
bool flg[20];
struct node{
	int u,v,w;
}e[1100010];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(){
	ct=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int eu=find(e[i].u),ev=find(e[i].v);
		if(eu==ev||(e[i].u>n&&!flg[e[i].u-n])||(e[i].v>n&&!flg[e[i].v-n]))continue;
		fa[eu]=ev;
		ans+=e[i].w;
		if(++ct==n+bc-1)return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++cnt]={i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int s=0;s<(1<<k);s++){
		ans=0;
		memset(flg,0,sizeof(flg));
		for(int i=1;i<=k;i++){
			if(1&(s>>(i-1))){
				ans+=c[i];
				bc++;
				flg[i]=1;
			}
		}
		kruskal();
		res=min(res,ans);
	}
	cout<<res<<"\n";
	return 0;
}
