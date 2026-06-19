#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=2e5+5;
int fa[N],n,m,k,c[15],a[15][N],cnt,fata,fatb,gg;
struct node{
	int a,b,c;
	bool friend operator < (node a,node b){return a.c<b.c;}
}edge[M*5],edge2[M],edge3[M];
void init(){
	for(int i=1;i<N;i++) fa[i]=i;
}
int find(int t){return (fa[t]==t)?t:fa[t]=find(fa[t]);}
void dfs(int t,int sum,int ans){
	if(t>k) return ;
	dfs(t+1,sum,ans);
	int cnt2=cnt,oo=0,ans2=ans+c[t];
	node edge3[M];
    memcpy(edge3,edge2,sizeof edge2);
	for(int i=1;i<=n;i++){
		edge2[++cnt]=(node){i,t+n,a[t][i]};
	}
	sort(edge2+1,edge2+cnt+1);
	init();
    for(int i=1;i<=cnt;i++){
    	int A=edge2[i].a,B=edge2[i].b,C=edge2[i].c;
    	fata=find(A),fatb=find(B);
    	if(fata!=fatb){
    		fa[fata]=fatb;ans2+=C;oo++;
		} 
		if(oo==sum+n) break ;
	}
   	gg=min(gg,ans2);
   	dfs(t+1,sum+1,ans+c[t]);
   	cnt=cnt2;
   	memcpy(edge2,edge3,sizeof edge3);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	init();
    for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&edge[i].a,&edge[i].b,&edge[i].c);
    sort(edge+1,edge+m+1);
    for(int i=1;i<=m;i++){
    	int A=edge[i].a,B=edge[i].b,C=edge[i].c;
    	fata=find(A),fatb=find(B);
    	if(fata!=fatb){
    		fa[fata]=fatb;
    		edge2[++cnt]=edge[i];
    		gg+=C;
		} 
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	dfs(1,0,0);
	printf("%lld\n",gg);
	return 0;
}
