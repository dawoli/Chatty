#include<bits/stdc++.h>
using namespace std;
long long t,ans,n,m,k,l,x,y,d;
string s[1005];
bool f[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=1;
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
		x--;
		y--;
		memset(f,0,sizeof(f));
		f[x][y]=1;
		for(long long i=0;i<n;i++)
		{
			cin>>s[i];
			for(long long j=0;j<s[i].length();j++)
				if(s[i][j]=='.')
					l++;
		}
		for(long long i=1;i<=k;i++)
		{
			if(d==0)
			{
				y++;
				if(0<=x&&x<n&&0<=y&&y<m&&s[x][y]=='.')
				{
					if(f[x][y]==0)ans++;
					f[x][y]=1;	
				}
				else 
				{
					y--;
					d=(d+1)%4;
				}
			}
			else if(d==1)
			{
				x++;
				if(0<=x&&x<n&&0<=y&&y<m&&s[x][y]=='.')
				{
					if(f[x][y]==0)ans++;
					f[x][y]=1;	
				}
				else 
				{
					d=(d+1)%4;
					x--;
				}
			}
			else if(d==2)
			{
				y--;
				if(0<=x&&x<n&&0<=y&&y<m&&s[x][y]=='.')
				{
					if(f[x][y]==0)ans++;
					f[x][y]=1;	
				}
				else 
				{
					y++;
					d=(d+1)%4;
				}
			}
			else if(d==3)
			{
				x--;
				if(0<=x&&x<n&&0<=y&&y<m&&s[x][y]=='.')
				{
					if(f[x][y]==0)ans++;
					f[x][y]=1;	
				}
				else 
				{
					x++;
					d=(d+1)%4;
				}
			}
			if(ans>=l)
			{
				ans=l;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
