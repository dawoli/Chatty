#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000000],b[1000000];
bool c[1000000];
long long cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
		if(a[i] == k)
		{
			cnt++;
			c[i] = true; 
		}
	}
	for(int i = n - 1;i >= 1;i--)
	{
		for(int j = 1;j <= i;j++)
		{
			a[j] = a[j] ^ b[j+n-i];
			if(a[j] == k)
			{
				int flag = true;
				for(int l = j;l <= j+n-i;l++)
				{
					if(c[l])
					{
						flag = false;
					}
					c[l] = true;
				}
				if(flag)
				{
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}
