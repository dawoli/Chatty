#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class PolygonConstructer
{
public:
	PolygonConstructer(multiset<int> &edge);
	int solve();
private:
	int dfs(int num, int sum, int mx, multiset<int>::iterator it);
	multiset<int> &edge;
};

PolygonConstructer::PolygonConstructer(multiset<int> &edge)
	: edge(edge) {}

int PolygonConstructer::solve()
{
	int sum = 0;

	for (auto it = edge.begin(); it != edge.end(); ++it)
	{
		sum += dfs(1, 0, 0, it);
	}

	return sum;
}

int PolygonConstructer::dfs(int num, int sum, int mx, multiset<int>::iterator it)
{
	int ans = 0;

	if (it != edge.end())
	{
		if (num < 3)
		{
			auto it0 = ++it;
			--it;
			for (auto it1 = it0; it1 != edge.end(); ++it1)
			{
				ans += dfs(num + 1, sum + *it, max(*it, mx), it1);
			}
		}
		else if (num >= 3)
		{
			auto it0 = ++it;
			--it;
			if (sum + *it > (max(*it, mx) << 1))
			{
				for (auto it1 = it0; it1 != edge.end(); ++it1){
					ans += 1 + dfs(num + 1, sum + *it, max(*it, mx), it1);
				}
			}
		}
	}
	
	return ans;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;

	cin >> n;

	multiset<int> sticks;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		sticks.insert(x);
	}

	PolygonConstructer pc(sticks);
	cout << pc.solve() << endl;

	return 0;
};
