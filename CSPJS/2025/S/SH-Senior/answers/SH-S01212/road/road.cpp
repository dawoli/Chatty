#include<bits/stdc++.h>
using namespace std;
int n,m,k,p[10105],cnt,a[10005];
long long cntcnt;
long long ans;
struct node{
	int u,v,w;
}g[1100005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int f(int u){
	if(u==p[u]) return u;
	return p[u]=f(p[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	for(int i=1;i<=k;i++){
		p[n+i]=n+i;
		int c;
		scanf("%d",&c);
		int zzz=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
			if(a[j]==0) zzz=j;
		}
		if(c==0){
			for(int j=1;j<=n;j++){
				node t;
				if(j!=zzz)
					t.u=zzz,t.v=j,t.w=a[j],g[++cnt]=t;
			}
		}
	}
//	cout<<cnt<<" ";
	sort(g+1,g+cnt+1,cmp);
	int cnt1=0;
	for(int i=1;i<=cnt;i++){
		if(cnt1>=n-1) break;
		int u=g[i].u,v=g[i].v,w=g[i].w;
		int uu=f(u),vv=f(v);
		if(uu!=vv){
			p[uu]=vv;
			if(u<=n&&v<=n) cnt1++;
			ans+=w;
		}
	}
//	cout<<cntcnt<<" ";
	printf("%lld",ans);
	return 0;
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
