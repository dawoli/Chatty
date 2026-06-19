#include<bits/stdc++.h>
using namespace std;
#define N 131400
#define M 19
#define ll long long
int T,n,m,k,f,a[N],_a[N],q[N],_x[10];
char c[M][N];int win[M][N];ll sum[M][N],ans;
void dfs(int n,int dep,int l,int r,int p){
	if(l==r){
		if(l>=n)win[dep][p]=-1;
		else win[dep][p]=l;
		sum[dep][p]=l+1;
		return;
	}
	int mid=(l+r)>>1;
	dfs(n,dep-1,l,mid,p<<1);
	dfs(n,dep-1,mid+1,r,p<<1|1);
	int x=win[dep-1][p<<1],y=win[dep-1][p<<1|1];
	if(x==-1&&y==-1){win[dep][p]=-1;sum[dep][p]=sum[dep-1][p<<1]+sum[dep-1][p<<1|1];}
	else if(y==-1){
		if(c[dep][p]=='0')win[dep][p]=(a[x]>=dep?x:-1),sum[dep][p]=(a[x]>=dep?sum[dep-1][p<<1]:sum[dep-1][p<<1|1]);
		else win[dep][p]=-1,sum[dep][p]=sum[dep-1][p<<1]+sum[dep-1][p<<1|1];
	}
	else{
		if(c[dep][p]=='0')win[dep][p]=(a[x]>=dep?x:y),sum[dep][p]=(a[x]>=dep?sum[dep-1][p<<1]:sum[dep-1][p<<1|1]);
		else win[dep][p]=(a[y]>=dep?y:x),sum[dep][p]=(a[y]>=dep?sum[dep-1][p<<1|1]:sum[dep-1][p<<1]);
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&_a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&q[i]);
	k=0;
	while((1<<k)<n)++k;
	for(int i=1;i<=k;++i)scanf("%s",c[i]);
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;++i)scanf("%d",&_x[i]);
		for(int i=1;i<=n;++i)a[i-1]=_a[i]^_x[i&3];
		ans=0;
		for(int i=1;i<=m;++i){
			f=0;
			while((1<<f)<q[i])++f;
			dfs(q[i],f,0,(1<<f)-1,0);
			ans^=(sum[f][0]*i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
