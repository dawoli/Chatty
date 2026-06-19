#include<bits/stdc++.h>
using namespace std;
int a[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		char hs,sz;
		int x,y;
		cin>>hs>>sz;
		if(hs=='S')
		{
			x=1;
		}
		else if(hs=='H')
		{
			x=2;
		}
		else if(hs=='D')
		{
			x=3;
		}
		else 
		{
			x=4;
		}
		if(sz=='A')
		{
			y=1;
		}
		else if(sz=='T')
		{
			y=10;
		}
		else if(sz=='J')
		{
			y=11;
		}
		else if(sz=='Q')
		{
			y=12;
		}
		else if(sz=='K')
		{
			y=13;
		}
		else
		{
			y=sz-'0';
		}
		a[x][y]=1;
	}
	int ans=52;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==1)
			{
				ans--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
