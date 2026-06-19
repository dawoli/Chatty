#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x0,y0,d0,cnt,nextd,tx,ty,t;
bool f[1005][1005];
string str[1005],strr;
char ch;
void dfs(ll nowx,ll nowy,ll nowd,ll depth)
{
	for(int i=1;i<=k;i++)
	{
		nextd=(nowd+1)%4;
		if(nowd==0)
		{
			tx=nowx;
			ty=nowy+1;
		}
		else if(nowd==1)
		{
			tx=nowx+1;
			ty=nowy;
		}
		else if(nowd==2)
		{
			tx=nowx;
			ty=nowy-1;
		}
		else if(nowd==3)
		{
			tx=nowx-1;
			ty=nowy;
		}
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&str[tx][ty]=='.')
		{
			if(f[tx][ty]==0)
			{
				f[tx][ty]=1;
				cnt++;
			}
			nowx=tx;
			nowy=ty;
		}
		else nowd=nextd;
	}
	
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cnt=1;
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld%lld",&x0,&y0,&d0);
		for(int i=1;i<=n;i++)
		{
			cin>>strr;
			str[i]=strr;
			str[i]=" "+str[i];
		}
		memset(f,0,sizeof(f));
		f[x0][y0]=1;
		dfs(x0,y0,d0,1);
		printf("%lld\n",cnt);
	}
	return 0;
} 
