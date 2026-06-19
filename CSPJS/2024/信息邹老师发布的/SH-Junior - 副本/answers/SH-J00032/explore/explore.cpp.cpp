#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	int m,n,t,k,x,y,d,ans;
	string a[1001];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=k;j++)
		{
			if(x+dx[d]<=n && x+dx[d]>0 && y+dy[d]<=m+1 && y+dy[d]>0  && a[x+dx[d]][y+dy[d]-1]=='.')
			{
				x+=dx[d];  
				y+=dy[d];
				ans++;
			}
			else
			{
				if(j==1)
				{
					ans++;
				}
				d=(d+1)%4;
			}
		}
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
