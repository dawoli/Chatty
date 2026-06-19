#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO{
char ibuf;
int rd(int x=0)
{
	for(;!isdigit(ibuf);ibuf=getchar());
	for(;isdigit(ibuf);ibuf=getchar())x=(x<<1)+(x<<3)+(ibuf^48);
	return x;
}
int rdc(int x=0)
{
	for(;!isdigit(ibuf);ibuf=getchar());
	x=(x<<1)+(x<<3)+(ibuf^48);ibuf=getchar();
	return x;
}
}using IO::rd;using IO::rdc;//namespace IO
int ap[262144];
int a[262144];
int cnt[262144];
int op[262144];
int upd[262144];
struct aaa
{
	int x,id;
}c[262144];
bool operator<(aaa a,aaa b)
{
	return a.x<b.x;
}
int f[262144];
int w[262144][18];
int cw[262144];
int bot[262144];
int botl[262144][18];
int botr[262144][18];
#define ins(x,y) (w[x][cw[x]++]=y)
void pushup(int x,int r)
{
	int L=x<<1,R=x<<1|1;
	if(!f[x])swap(L,R);
	if(bot[R]||a[w[R][0]]<r)
	{
		cw[x]=cw[L];bot[x]=bot[L];for(int i=0;i<bot[x];i++)botl[x][i]=botl[L][i],botr[x][i]=botr[L][i];
		for(int i=0;i<cw[x];i++)w[x][i]=w[L][i];
	}
	else cw[x]=bot[x]=0;
	for(int i=0;i<bot[R];i++)botl[x][bot[x]]=botl[R][i],botr[x][bot[x]++]=botr[R][i];
	for(int i=0;i<cw[R];i++)if(a[w[R][i]]>=r)ins(x,w[R][i]);
}
int sums(int l,int r)
{
	return (r-l+1)*(r+l)/2;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n=rd(),m=rd();
	for(int i=0;i<n;i++)ap[i]=rd();
	for(int j=1;j<=m;j++)
	{
		c[j].x=rd(),c[j].id=j;
	}
	int p=0;while((1<<p)<n)p++;
	for(int i=p-1;i>=0;i--)
	{
		for(int j=1<<i;j<(1<<i+1);j++)f[j]=rdc();
	}
	sort(c+1,c+m+1);
	int cur=0;int cnt=0;
	for(int i=1;i<=m;i++)
	{
		for(;cur<c[i].x;cur++)op[cnt]=1,upd[cnt++]=cur;
		op[cnt]=2;upd[cnt++]=c[i].id;
	}
	int T=rd();
	while(T--)
	{
		int x[4];for(int i=0;i<4;i++)x[i]=rd();
		for(int i=0;i<n;i++)a[i]=ap[i]^x[i+1&3];
		for(int i=1;i<(1<<p+1);i++)
		{
			cw[i]=0,bot[i]=1;//full of bots first
			int L=i,R=i+1;while(L<(1<<p))L<<=1,R<<=1;
			botl[i][0]=L,botr[i][0]=R;
		}
		int sum=0;
		int cur=1;
		for(int i=0;i<cnt;i++)
		{
			if(op[i]==1)
			{
				//add upd[i]
				cur=max(cur,(upd[i]&-upd[i])<<1);
				int x=upd[i]|1<<p;
				bot[x]=0;ins(x,upd[i]);
				int R=0;
				int rt=(1<<p)/cur;
				while(x>>=1)pushup(x,++R);
			}
			else
			{
				//qry,id=upd[i]
				int x=(1<<p)/cur;
				int ans=0;
				for(int i=0;i<cw[x];i++)ans+=w[x][i]+1;
				for(int i=0;i<bot[x];i++)ans+=sums(botl[x][i]+1-(1<<p),botr[x][i]-(1<<p));
					sum^=ans*upd[i];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}