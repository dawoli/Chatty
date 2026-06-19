#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005] = {0},b[10005],c,d,n,m,mx,l,x,r,h,k,sum;
int main()
{
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	c = 0;
	for (int i = 1; i <= n; i++)
	{
		c = 0;
		if(sum >= mx)
		{
			mx = sum;
		}
		sum = 0;
		for (int j = i; j <= n; j++)
		{
			c = c ^ a[j];
			if(c == k)
			{
				sum++;
				c = 0;
			}
		}
	}
	cout << mx;
	return 0;
}
