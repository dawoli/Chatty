#include <bits/stdc++.h>
using namespace std;
int a[100005];
stack<int> st[100005];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int cur = 1,tmp = n;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != a[i - 1])
		{
			cur = 1;
		}
		while(!st[cur].empty() && a[i] == st[cur].top())
		{
			cur++;
		}
		if(!st[cur].empty())
		{
			if(a[i] > st[cur].top())
			{
				st[cur].pop();
				tmp--;
				st[cur].push(a[i]);
			}
		}
		if(st[cur].empty())
		{
			st[cur].push(a[i]);
		}
	}
	cout << tmp;
	return 0;
}
