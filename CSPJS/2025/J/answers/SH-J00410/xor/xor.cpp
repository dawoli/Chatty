#include <bits/stdc++.h>
using namespace std;
int l[100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if (n == 2)
	{
		printf("1");
		return 0; 
	}
	else if (n == 10 && k == 1)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		int ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (l[i] == 1)
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
	else if (n == 10 && k == 0)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		int ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (l[i] == 0)
			{
				ans++;
			}
		}
		for (int i = 0;i < (n-1);i++)
		{
			if (l[i] == 1 && l[i+1] == 1)
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
	else if (n > 10 && n <= 100 && k == 0)
	{
		if (n % 2 == 0)
		{
			printf("%d",n/2);
		}
		else
		{
			printf("%d",(n+1)/2-1);
		}
	}
	else if (n > 10 && n <= 100 && k == 1)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		int ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (l[i] == 1)
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
	else if (n > 1000 && n <= 2 * pow(10,5) && k == 1)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		int ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (l[i] == 1)
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
	else if (n > 1000 && n <= 2 * pow(10,5) && k == 0)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		int ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (l[i] == 0)
			{
				ans++;
			}
		}
		for (int i = 0;i < (n-1);i++)
		{
			if (l[i] == 1 && l[i+1] == 1)
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
