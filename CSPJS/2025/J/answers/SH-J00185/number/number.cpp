#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[10]; // 存储各个数字出现的次数 

// 映射为数字 
void get_num(char c)
{
	if (c >= '0' && c <= '9')
		cnt[c-'0']++;
}

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
		get_num(s[i]);
	
	// 贪心策略：先从数字大的开始填
	for (int i = 9; i >= 0; i--)
	{
		while (cnt[i])
		{
			cnt[i]--;
			cout << i;
		}
	}
	
	return 0;
}
