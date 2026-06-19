#include<bits/stdc++.h>
using namespace std;


const int maxn=1e4+10;
long long n,m,k,fa[maxn],cnt,c[maxn][maxn],c1[maxn],sum;
struct node{
	int u,v,w;
}e[maxn];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long find(long long i){
	if(fa[i]==i) return i;
	else return fa[i]=find(fa[i]);
}
void merge(long long i,long long j){
	long long x=find(i),y=find(j);
	fa[y]=x;
}
void cru(){
	cnt=1;
	for(int i=1;i<=m;i++){
		long long u=e[i].u;
		long long v=e[i].v;
		if(find(u)==find(v)) continue;
		merge(u,v);
		cnt++;
		sum+=e[i].w;
		if(cnt==n) break;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		long long x;
		cin>>x;
		c1[i]=x;
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	for(int k1=1;k1<=k;k1++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[++m].u=i;
				e[m].v=j;
				e[m].w=c[k1][i]+c[k1][j]+c1[k1];
			} 
		}
	}
	sort(e+1,e+1+m,cmp);
	cru();
	cout<<sum;
	
	return 0;
}
