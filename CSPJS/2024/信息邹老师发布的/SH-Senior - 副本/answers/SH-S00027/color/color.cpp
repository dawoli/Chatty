#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int n, a[200005], ans;
bool color[200005];

void dfs1(int x, int c)
{
	int score = c;
	int last = 0;
	for(int i = x-1; i >= 1; i--)
	{
		if(color[i] == color[x])
		{
			last = i;
			break;
		}
	}
	if(last != 0)
	{
		if(a[last] == a[x]) score += a[x];
	}
	if(x == n)
	{
		ans = max(ans, score);
		return;
	}
	color[x+1] = 0;
	dfs1(x+1, score);
	color[x+1] = 1;
	dfs1(x+1, score);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			color[i] = 0;
			cin >> a[i];
		}
		dfs1(1, 0);
		cout << ans << endl;
	}
	return 0;
}
