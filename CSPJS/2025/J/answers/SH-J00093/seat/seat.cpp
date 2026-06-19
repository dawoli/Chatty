#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[101][101],s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int z=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				z++;
				b[i][j]=a[z];
				if(b[i][j]==s)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);	
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>0;j--)
			{
				z++;
				b[i][j]=a[z];
				if(b[i][j]==s)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);	
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
