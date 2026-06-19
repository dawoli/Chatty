#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int b[1001];  
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[++cnt]=a[i][j];
		 } 
	}
	int x=b[1];
	sort(b+1,b+n*m+1,cmp);
	int cnt2=0;
	for(int i=1;i<=n*m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				++cnt2;
				if(b[cnt2]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				++cnt2;
				if(b[cnt2]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			
			}
		}
	}
	return 0;
 } 
