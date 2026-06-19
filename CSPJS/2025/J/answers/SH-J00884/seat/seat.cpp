#include <iostream>
#include <algorithm>
using namespace std;

int a[150];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rs,cur=0;
	cin >> n >> m;
	cin >> rs;
	a[1]=rs;
	for(int i=2;i<=n*m;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[++cur]==rs)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[++cur]==rs)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
