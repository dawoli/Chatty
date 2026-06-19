#include <bits/stdc++.h>
using namespace std;

int n,m,rc;
int seat[110][110],sc[110];

bool check(int x, int y)
{
	return (x>y);
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>sc[i];
		if (i==1)
		{
			rc=sc[i];
		}
	}
	sort(sc+1,sc+n*m+1,check);
	int k=1;
	for (int i=1;i<=n;i++)
	{
		if (i%2==0)
		{
			for (int j=m;j>=1;j--)
			{
				seat[j][i]=sc[k];
				k++;
			}
		}
		else
		{
			for (int j=1;j<=m;j++)
			{
				seat[j][i]=sc[k];
				k++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i%2==0)
		{
			for (int j=m;j>=1;j--)
			{
				if (seat[j][i]==rc)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else
		{
			for (int j=1;j<=m;j++)
			{
				if (seat[j][i]==rc)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
