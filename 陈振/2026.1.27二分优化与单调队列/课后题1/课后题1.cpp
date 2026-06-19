#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001],ps[200001],ans=INT_MIN;
deque<int> dq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	partial_sum(a+1,a+n+1,ps+1);
	/*
	for(int i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	*/
	for (int i = 1; i <= n; i++)
	{
		while (!dq.empty() && dq.front() < i - m)
		{
			dq.pop_front();
		}
		if (!dq.empty())
		{
			int sum = ps[i] - ps[dq.front()];
			if (sum > ans)
			{
				ans = sum;
			}
		}
		else
		{
			int sum = ps[i] - ps[i - 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
		while (!dq.empty() && ps[dq.back()] >= ps[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << ans << endl;
	return 0;
}