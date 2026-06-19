#include<bits/stdc++.h>
#define ar3 array<int,3>
#define ar2 array<int,2>
#define int long long 
using namespace std;
const int N=1000115,inf=1ll<<60;
int n,m,k,cnt;
ar3 a[N],aa[N];
int c[15]; 

vector<ar3> e[N];
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int ans=inf;
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int sm=0; 
	for(int i=1;i<=m;i++){
		int u=a[i][1],v=a[i][2],w=a[i][0];
		if(find(u)==find(v))continue;
		aa[++cnt]=a[i];		
		sm+=w;
		fa[find(u)]=find(v);
	}
	ans=sm;
//	printf("sm : %d\n",sm);
}
int pcnt=0;
void upd(int &ans,ar3 x){
	int u=x[1],v=x[2],w=x[0];
	if(find(u)!=find(v)){
//		printf("%d %d\n",u,v);
		fa[find(u)]=find(v);
		ans+=w;
		pcnt++;
	}
}
int cal(int x){
	int sm=0;
	for(int i=0;i<k;i++)if(x&(1<<i)){
//		puts("WA");
//		printf("kkk %lld\n",c[i+1]);
		sm+=c[i+1];
	}
//	printf("kkk %lld\n",sm);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}	
	vector<int> p(15,0);
	int i=1;
	pcnt=0;
	while(1){
		int mn=0;
		for(int j=0;j<k;j++)if(x&(1<<j)){
			if(p[j]>=e[j].size())continue;
			if(mn==0||e[j][p[j]][0]<e[mn][p[mn]][0]){
				mn=j;
			}
		}
		if((x&(1<<mn))&&p[mn]<e[mn].size()){
			if(i<=cnt&&aa[i][0]<e[mn][p[mn]][0]){
				upd(sm,aa[i++]);
			}else{
				upd(sm,e[mn][p[mn]++]);
			}
		}else{
			if(i<=cnt)
			
			upd(sm,aa[i++]); 
		} 
		if(pcnt==n+__builtin_popcount(x)-1){
//			puts("WA");
			break;
		}
	}
//	printf("%d %d\n-----\n",x,sm);
	return sm;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		a[i]={w,u,v};
	}
	sort(a+1,a+1+m);
	init(); 
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			int x;scanf("%lld",&x);
			e[i-1].push_back({x,i+n,j});
		}
		sort(e[i-1].begin(),e[i-1].end());
	}
//	printf("kkk %d %d %d %d\n",c[4],c[1],c[2],c[3]);
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,cal(i));
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/ 
//Ren5Jie4Di4Ling5%
