#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500010], sum[500010];
struct node
{
	int be, en;	
};
bool cmp(node a, node b)
{
	return a.be <= b.be;
}
node b[500010];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, flag = 1, flag1 = 1, cnt0 = 0, cnt1 = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) flag = 0;
		if(a[i] != 1 && a[i] != 0) flag1 = 0;
		if(a[i] == 0) cnt0++;
		if(a[i] == 1) cnt1++;
		sum[i] = sum[i - 1] ^ a[i];
	}
	if(flag) 
	{
		cout << n / 2 << endl;
		return 0;
	}
	else if(flag1)
	{
		if(k == 0)
		{
			int ans = 0, k1 = 0, k2 = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 0)k1++;
				else
				{
					ans += k1 / 2;
					k1 = 0;
				}
				if(a[i] == 1)k2++;
				else
				{
					ans += k2 / 2;
					k2 = 0;
				}
			}
			ans = max(ans, cnt1 / 2);
			cout << ans << endl;
			return 0;
		}
		if(k == 1)
		{
			cout << cnt1 << endl;
			return 0;
		}
	}
	else
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				int x = sum[j] ^ sum[i - 1];
				if(x == k)
				{
				 	b[++cnt].be = i;
				 	b[cnt].en = j;
				 	break;
				} 
				
			}
		}
		int cnt2 = 0;
		sort(b + 1, b + cnt + 1, cmp);
		int x1;
		for(int i = 1; i <= cnt; i++)
		{
			if(b[i].be > x1) 
			{
				cnt2++;
				x1 = max(x1, b[i].en);
			}
		}
		cout << cnt2 << endl;
	}
	return 0;
}
