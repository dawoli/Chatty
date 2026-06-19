#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= 200000; j++)
		{
			a[j] = 0;
		}
		int u;
		cin >> u;
		for(int j = 1; j <= u; j++)
		{
			cin >> a[j];
		}
	}
	return 0;
}
