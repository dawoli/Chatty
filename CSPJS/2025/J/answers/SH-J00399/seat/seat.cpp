#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int l[maxn];
int cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=0;
	int n,m;
	int p=1;
	cin>>n>>m;
	int a[m][n];
	for(int i=1;i<=n*m;i++)
	{
		cin>>l[i];
		x=l[1];
	}
	sort(l,l+n*m);
	for(int i=2;i<=n*m;i++)
	{
		if(l[i]!=x)
		{
			cnt++;
		}
	}
	cnt-=1;
	cout<<cnt<<endl;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=p;
				p++;
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
				a[j][i]=p;
				p++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==cnt)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
