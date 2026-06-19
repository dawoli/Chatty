#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005],h[1005][1005];
int t,n,m,x,y,d,k,ans=0;
string s;
void f()
{
	vis[x][y]=true;
	if(d==0)
	{
		if(y+1<=m&&h[x][y+1]) y++;
		else d++;
	}
	else if(d==1)
	{
		if(x+1<=n&&h[x+1][y]) x++;
		else d++;
	}
	else if(d==2)
	{
		if(y-1>0&&h[x][y-1]) y--;
		else d++;
	}
	else if(d==3)
	{
		if(x-1>0&&h[x-1][y]) x--;
		else d=0;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int tmp=0;tmp<t;tmp++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		for(int i=0;i<=1000;i++)
			for(int j=0;j<=1000;j++) vis[i][j]=false;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.length();j++)
			{
				if(s[j]=='.') h[i][j+1]=1;
				else h[i][j+1]=0;
			}
		}
		for(int i=0;i<k;i++)
			f();
		vis[x][y]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
