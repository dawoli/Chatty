#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+10;
int n, k, pos = 0, cnt = 0, lst = 0;
int a[N], s[N];
bool vilid = 1; // 特判全1 
bool flag = 1; // 特判01串 

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1) vilid = 0;
		if (a[i] != 1 && a[i] != 0) flag = 0;
		s[i] = s[i-1] ^ a[i]; // 预处理前缀异或和
	}
	
	// 特判：10pts 
	if (vilid && k == 0)
	{
		cout << n / 2 << '\n';
		return 0;
	}
	
	// 特判：20pts，目前30pts 
	if (flag && k == 1)
	{
		pos = 1;
		while (pos <= n)
		{
			if (a[pos] == 1)
			{
				cnt++;
				pos++;
			}
			else if (pos < n && a[pos] + a[pos+1] == 1)
			{
				cnt++;
				pos += 2;
			}
			else
			{
				pos++;
			}
		}
		cout << cnt << '\n';
		return 0;
	}
	
	if (flag && k == 0)
	{
		pos = 1;
		while (pos <= n)
		{
			if (a[pos] == 0)
			{
				cnt++;
				pos++;
			}
			else if (pos < n && a[pos] + a[pos+1] == 2)
			{
				cnt++;
				pos += 2;
			}
			else
			{
				pos++;
			}
		}
		cout << cnt << '\n';
		return 0;
	}
	
	// 使用前缀和以及双指针进行
	pos = 1, lst = 0; // 开始时指针默认在起点，默认上次匹配位置在起点的前一位 
	for (int j = 1; j <= n; j++)
	{
		for (int i = lst+1; i <= j; i++)
		{
			int tmp = s[j] ^ s[i-1];
			if (tmp == k)
			{
				cnt++;
				lst = j;
				break;
			}
		}
	}
	cout << cnt << '\n';
	return 0; 
}
