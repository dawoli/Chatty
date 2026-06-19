#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,mp[1050][1050],e[1050][1050],ans;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int xn,yn;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		char tmp[m+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				mp[i][j]=0,e[i][j]=0;
		e[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>tmp[j];
				if(tmp[j]=='.')mp[i][j]=1;
			}
		while(k--)
		{
			if(d==0)xn=x,yn=y+1;
			if(d==1)xn=x+1,yn=y;
			if(d==2)xn=x,yn=y-1;
			if(d==3)xn=x-1,yn=y;
			if(mp[xn][yn]==1)
			{
				x=xn,y=yn;
				e[x][y]=1;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=e[i][j];
		cout<<ans<<endl;
	}
	return 0;
} 
