#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n;
	cin >> n;
	int l[n+5];
	for (int i = 1;i <= n;i ++)
	{
		cin >> l[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		for (int j = i + 1;j <= n;j ++)
		{
			if (l[i] > l[j])
			{
				swap (l[i],l[j]);
			}
		}
	}
	for (int i = 3;i <= n;i ++)
	{
		for (int j = 1;j <= n - i + 1;j ++)
		{
				
		}
	}	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
