#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int b[1001][1001]={0,0};
long long T,ans,n,m,k,x,y,d,i,j;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	for(i=1;i<=1001;i++)
		for(j=1;j<=1001;j++)
			a[i][j]='x';
	cin>>T;
	while(T--)
	{
		ans=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				b[i][j]=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];
		b[x][y]=1;
		while(1)
		{
			if(k==0)
				break;
			if(d==0)
			{
				if(a[x][y+1]=='.')
					y++,b[x][y]++,k--;	
				else
					d=(d+1)%4,k--;
				continue;
			}
			if(d==1)
			{
				if(a[x+1][y]=='.')
					x++,b[x][y]++,k--;
				else
					d=(d+1)%4,k--;
				continue;
			}
			if(d==2)
			{
				if(a[x][y-1]=='.')
					y--,b[x][y]++,k--;
				else
					d=(d+1)%4,k--;
				continue;
			}
			if(d==3)
			{
				if(a[x-1][y]=='.')
					x--,b[x][y]++,k--;
				else
					d=(d+1)%4,k--;
				continue;
			}
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(b[i][j]!=0)
					ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
