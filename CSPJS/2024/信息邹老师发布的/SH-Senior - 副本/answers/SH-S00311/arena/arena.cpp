//12
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=15;
int m,K,k,r;
int aa[N],a[N],b[N],x[N],c[N];
char s[5][N];
bool tag[N];
int getk(int x)
{
	if(x==1) return 0;
	if(x<=2) return 1;
	if(x<=4) return 2;
	return 3;
}
int par[N];
int check()
{
	int R=1;
	for(int i=1;i<=r;i++) par[i]=i;
	for(int i=1;i<=(r>>1);i++)
	{
		int lz=par[2*i-1],zl=par[2*i];
		if(s[R][i]=='1') swap(lz,zl);
		if(a[lz]>=R) par[i]=lz;
		else par[i]=zl; 
	}
	if(k==1) return par[1];
	R=2;
	for(int i=1;i<=(r>>2);i++)
	{
		int lz=par[2*i-1],zl=par[2*i];
		if(s[R][i]=='1') swap(lz,zl);
		if(a[lz]>=R) par[i]=lz;
		else par[i]=zl;
	}
	if(k==2) return par[1];
	R=3;
	for(int i=1;i<=1;i++)
	{
		int lz=par[2*i-1],zl=par[2*i];
		if(s[R][i]=='1') swap(lz,zl);
		if(a[lz]>=R) par[i]=lz;
		else par[i]=zl;
	}
	return par[1];
}
void dfs(int d)
{
	if(d>r) 
	{
		tag[check()]=1; return;
	}
	for(int i=0;i<=3;i++)
	{
		a[d]=i;
		dfs(d+1); 
	}
}
int solve(int n)
{
	k=getk(n); r=1<<k;
	if(k==0) return 1;
	memset(tag,0,sizeof(tag));
	dfs(n+1);
	int ret=0;
	for(int i=1;i<=r;i++) if(tag[i]) ret+=i;
//	for(int i=1;i<=r;i++) printf("%d ",tag[i]); printf("\n");
	return ret; 
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&aa[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	K=getk(n);
	for(int i=1;i<=K;i++) scanf("%s",s[i]+1);
	int qwq;
	scanf("%d",&qwq);
	int ret,ans;
	while(qwq--)
	{
		for(int i=0;i<=3;i++) scanf("%d",&x[i]);
		for(int i=1;i<=n;i++) b[i]=a[i]=aa[i]^x[i%4];
		ans=0;
		for(int i=1;i<=m;i++)
		{
			ret=solve(c[i]);
			ans^=(ret*i);
			for(int j=1;j<=n;j++) a[i]=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

