#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],h[5005],sh[5005],ans,x;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		h[a[i]] = 1;
	}
	if(n == 3)
	{
		int sum = 0,mx = 0;
		for(int i = 1;i <= 3;i++)
		{
			mx = max(a[i],mx);
			sum += a[i]; 
		}
		if(sum > 2*mx)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= 5000;i++)
	{
		sh[i] = sh[i-1] + h[i];
	}
	for(int i = 1;i <= n;i++)
	{
		b[i] = b[i-1] + a[i];
		if(b[i] > a[i] * 2)
		{
			x = i;
			break;
		}
	}
	for(int i = x;x <= n;x++)
	{
		int mx = b[i] - (a[i] * 2 + 1);
		for(int j = 1;j <= i;j++)
		{
			if(mx > a[j])
			{
				ans += sh[mx - a[j]];
			} 
		}
	}
	cout << ans;
}
