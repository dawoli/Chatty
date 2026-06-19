#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15]={0};
int te[105];
int cnt=0;
int y=0;
int N=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	N=n*m;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			a[j][i]=(i-1)*n+j;
		}
	}
	for(int i=2;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			a[j][i]=i*n-j+1;
		}
	}
	for(int i=1;i<=N;i++)
	{
		cin>>te[i];
	}
	cnt=te[1];
	sort(te+1,te+N+1,cmp);
	for(int i=1;i<=N;i++)
	{
		if(te[i]==cnt)
		{
			y=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==y)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
