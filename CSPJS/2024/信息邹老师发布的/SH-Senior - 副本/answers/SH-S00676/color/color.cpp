#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
vector<int> v_0;
vector<int> v_1;
int ans = 0;

void dfs(int step)
{
	if (step == n + 1)
	{
		int num = 0;
		for (int i = 1; i < v_0.size(); i++)
			if (v_0[i] == v_0[i-1])
				num += v_0[i];
		for (int i = 1; i < v_1.size(); i++)
			if (v_1[i] == v_1[i-1])
				num += v_1[i];
		ans = max(ans, num);
		return;
	}
	v_0.push_back(a[step]);
	dfs(step + 1);
	v_0.pop_back();
	v_1.push_back(a[step]);
	dfs(step + 1);
	v_1.pop_back();
	return;
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
