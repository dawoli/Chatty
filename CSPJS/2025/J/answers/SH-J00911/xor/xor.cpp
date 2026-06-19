#include <bits/stdc++.h>
using namespace std;
int a[500009];
bool vst[500009];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)	//区间长度
	{
		int tmp = 0;
		queue<int> err;    //vst[i] == true 且存在于当前区间中 
		for (int j = 0; j < i; ++j)
		{
			tmp ^= a[j];
			if (vst[j])
				err.push(j);
		}
		if (err.empty())
			if (tmp == k)
			{
				++ans;
				for (int q = 0; q < i; ++q)
					vst[q] = true;
			}
		for (int j = 1; j + i - 1 < n; ++j)
		{
			tmp ^= a[j - 1];
			tmp ^= a[j + i - 1];
			if (!err.empty())
				if (err.front() == j - 1)
					err.pop();
			if (vst[j + i - 1])
				err.push(j + i - 1);
			if (err.empty())
				if (tmp == k)
				{
					++ans;
					for (int q = j; q <= j + i - 1; ++q)
						vst[q] = true;
				}
		}
	}
	cout << ans;
	return 0;
}
