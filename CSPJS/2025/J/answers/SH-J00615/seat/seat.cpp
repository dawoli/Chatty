#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,x = 1,y = 1,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i ++)
	{
		cin>>a[i];
	}
	k = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = n * m;i >= 1;i --)
	{
		if(a[i] == k)
		{
			cout<<y<<" "<<x;
			break;
		}
		if(y % 2 == 1)
		{
			if(x == n)
			{
				y += 1;
			}
			else
			{
				x += 1;
			}
		}
		else
		{
			if(x == 1)
			{
				y += 1;
			}
			else
			{
				x -= 1;
			}
		}
	}
	return 0;
} 
