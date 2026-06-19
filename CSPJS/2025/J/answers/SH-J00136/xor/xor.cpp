#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[256];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int u = 0;
	if(k == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
			{
				u++;
			}
			b[a[i]]++;
		}
		for(int i = 1; i <= 255; i++)
		{
			u += b[i] / 2;
		}
	}
	if(k == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1)
			{
				u++;
			}
		}
	}
	cout << u;
	return 0;
} 
/*
freopen(".in","r",stdin);
freopen(".out","w",stdout);

*/
