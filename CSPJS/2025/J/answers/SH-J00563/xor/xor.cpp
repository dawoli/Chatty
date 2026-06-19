#include <iostream>
#include <vector>

using namespace std;

const int N = 500010;

int a[N];
struct Node { int id; int i; int j; };
vector<Node> Nodes; // 异或和为k的所有区间 
int ans = 0;
bool mark[N];
// 使每个若干个不相交区间的异或和均为k，求区间数量的最大值 
bool is_mark(Node n)
{
	int l = n.i, r = n.j;
	for (int i = l; i <= r; i++)
	{
		if (mark[i])
			return true;
	}
	return false;
}
bool domark(Node n)
{
	int l = n.i, r = n.j;
	for (int i = l; i <= r; i++)
	{
		mark[i] = true;
	}
}
// 每个区间不应相交，故可以无脑清除 
bool demark(Node n)
{
	int l = n.i, r = n.j;
	for (int i = l; i <= r; i++)
	{
		mark[i] = false;
	}
}

// 枚举所有区间组合，求最大ans 
void dfs(int step = 0, int count = 0)
{
	if (step == Nodes.size())
	{
		ans = max(ans, count);
		return;
	}
	if (!is_mark(Nodes[step]))
	{
		domark(Nodes[step]);
		dfs(step + 1, count + 1);
		demark(Nodes[step]);
	}

	dfs(step + 1, count);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int cnt = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum ^= a[k];
			}
			if (sum != k)
				continue;
			Nodes.push_back({cnt++, i, j});
		}
	}
	
	dfs();
	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 2
2 1 0 3

ans = 2

4 3
2 1 0 3

ans = 2

4 0
2 1 0 3

ans = 1

*/

