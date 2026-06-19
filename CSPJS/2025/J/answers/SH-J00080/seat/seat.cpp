#include<bits/stdc++.h>
using namespace std;

int a[15][15];
int c[230];
int n,m;
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	r=c[1];
	sort(c+1,c+n*m+1,cmp);
	int index1=1;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			a[j][i]=c[index1];
			index1++;
		}
		index1+=n;
	}
	int index2=2*n;
	for(int i=2;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			a[j][i]=c[index2];
			index2--;
		}
		index2+=3*n;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
