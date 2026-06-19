#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7,M=1e4+7;
struct edge{
	int u,v,w;
	inline void operator =(const edge &b){
		u=b.u;
		v=b.v;
		w=b.w;
	}
}e1[N],tr[M*11];
bool cmp(edge a,edge b){
	return (a.w<b.w);
}
long long ans=0,sum=0;
int cntp,cnto,kkk,u,v,cnt,cnt2,pl,pl2,llen,rlen,cntk;
int f[M+17],tmt[17],km;
inline int find(int u){return (u==f[u])?u:f[u]=find(f[u]);}
int n,m,k;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	for(int j=0;j<k;j++){
		scanf("%d",&tmt[j]);
		for(int i=1;i<=n;i++)
			scanf("%d",&km),tr[++cnt2]={j+n+1,i,km};
	}
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=m;i++){
		u=find(e1[i].u),v=find(e1[i].v);
		if(u==v)continue;
		tr[++cnt2]=e1[i];
		f[u]=v;
		ans+=e1[i].w;
	}
	sort(tr+1,tr+cnt2+1,cmp);
	for(int j=1;j<(1<<k);j++){
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		sum=0;
		for(int p=0;p<k;p++)
			if(j>>p&1)
				sum+=tmt[p];
		for(int i=1;i<=cnt2;i++){
			if(tr[i].u>n)
				if(!(j>>(tr[i].u-n-1)&1))
					continue;
			u=find(tr[i].u),v=find(tr[i].v);
			if(u==v)continue;
			f[u]=v;
			sum+=tr[i].w;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
/*
今年 S 好难啊！！！

I love wcj

喵~ 
*/ 
