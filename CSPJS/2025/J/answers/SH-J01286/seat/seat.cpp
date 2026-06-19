#include<bits/stdc++.h>
using namespace std;
int n,m,pre,me;
int map[15][15];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m>>me;
	for(int i = 2;i<=n*m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>me)
		{
			pre++;
		}
	}
	pre++;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(i%2 == 0)
			{
				if (pre == i*n-j+1)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
			else
			{
				if (pre == (i-1)*n+j)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

		
	
