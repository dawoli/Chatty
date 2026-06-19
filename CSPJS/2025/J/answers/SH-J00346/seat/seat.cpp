#include<bits/stdc++.h>
using namespace std;
int n,m,a[107];
int ans1,ans2,t;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n*m;i++)
	{
		cin >> a[i];
	}
	t = a[0];
	sort(a,a+n*m,cmp);
	for(int i = 0;i < n*m;i++)
	{
		if(a[i] == t)
		{
			t = i+1;
		}
	}
	int x,y;
	x = t/n;
	y = t%n;
	if(y == 0)
	{
		ans1 = x;
		if(x%2 == 0)
		{
			ans2 = 1;
		}
		if(x%2 == 1)
		{
			ans2 = n;
		}
	}
	if(y != 0)
	{
		ans1 = x+1;
		if(x%2 == 0)
		{
			ans2 = y;
		}
		if(x%2 == 1)
		{
			ans2 = m-y+1;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
