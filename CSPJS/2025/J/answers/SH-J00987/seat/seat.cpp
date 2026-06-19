#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int rmark=b[1];
	int seat=1;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)	
		{
			for(int j=1;j<=n;j++)		
			{
				a[j][i]=b[seat];
				seat++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)		
			{
				a[j][i]=b[seat];
				seat++;
			}		
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==rmark)
			{
				cout<<j<<" "<<i;
				return 0;
			} 
		}
	}
	return 0;
}
