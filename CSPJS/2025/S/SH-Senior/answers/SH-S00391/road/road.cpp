#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v;
	long long w;
	bool operator <(edge a)const{
		return w<a.w;
	}
};
const int M=2.1e6,N=1.1e4,K=15;
int n,m,k,a[K][N],c[N];
edge e[M];
void input(){
	//printf("tkr orz\n");
	scanf("%d%d%d",&n,&m,&k);
	//printf("tkr orz %d %d %d\n",n,m,k); 
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int j=1;j<=k;j++){
		scanf("%d",&c[j]);
		for(int i=1;i<=n;i++)scanf("%d",&a[j][i]);
	}
}
namespace solveBF{
	int fa[N];
	long long ans=4e18;
	edge eg[N*K];
	void init(){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		if(fa[x]==x)return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		fa[find(y)]=find(x);
	}
	void solve(){
		int idx=0;
		for(int j=1;j<=k;j++){
			for(int l=1;l<=n;l++)eg[++idx]={j+n,l,a[j][l]};
		}
		sort(e+1,e+m+1);
		sort(eg+1,eg+idx+1);
		for(int i=0;i<(1<<k);i++){
			//printf("%d\n",i);
			long long res=0,cnt=n-1;
			for(int j=1;j<=k;j++){
				if(((i>>(j-1))&1)==0)continue;
				cnt++;
				res+=c[j];
			}
			init();
			for(int j=1,l=1;l<=idx or j<=m;){
				edge cur;
				while(l<=idx and ((i>>(eg[l].u-n-1))&1)==0)l++;
				if(l<=idx and eg[l].w<=e[j].w){
					cur=eg[l]; 
					l++;
				}
				else if(j<=m){
					cur=e[j];
					j++;
				}
				if(cnt==0 or res+cnt*cur.w>ans)break;
				int fu=find(cur.u),fv=find(cur.v);
				if(fu==fv)continue;
				res+=cur.w;
				cnt--;
				merge(fu,fv);
			}
			if(cnt==0)ans=min(ans,res);
		}
		printf("%lld",ans);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	solveBF::solve();
	return 0;
}
