#include<bits/stdc++.h>
using namespace std;
int n,m,x,s,r,c,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	x = n*m;
	for(int i = 1;i <= x;i++)
	{
		cin >> a[i];
		if(i == 1)
		{
			r = a[i];
		}
	}
	sort(a+1,a+x+1);
	int s = lower_bound(a+1,a+x+1,r) - a;
	s = x - s + 1;
	int r = (s+n-1)/n; 
	cout << r << " ";
	if(r % 2 == 0)
	{
		cout << n - (s - (r-1) * n) + 1;
	}
	else
	{
		cout << s - (r-1) * n;
	}
} 
