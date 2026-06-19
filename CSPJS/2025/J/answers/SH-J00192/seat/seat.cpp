#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b[1];
	int c=b[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n*m+1);
	int p=1,d=n*m;
	bool f=1;
	while(f)
	{
		if(p%2)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[d]==c)
				{
					cout<<p<<" "<<i;
					f=0;
					break;
				}
				d--;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(b[d]==c)
				{
					cout<<p<<" "<<i;
					f=0;
					break;
				}
				d--;
			}
		}
		p++; 
	}
	return 0;
}
