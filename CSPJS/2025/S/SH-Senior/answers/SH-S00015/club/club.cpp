#include <iostream>
#include <algorithm>
#include <fstream>
using ll = long long;
const int maxn = 1e5 + 5;

int n;

struct Node
{
	int part1, part2, part3;
};
Node member[maxn];

ll dfs(int cnt1, int cnt2, int pos)
{
	int cnt3 = pos - cnt1 - cnt2;
	int max = n >> 1;
	if(cnt1 > max || cnt2 > max || cnt3 > max)
		return -10000000;

	if(pos > n)
		return 0;

	ll to1 = dfs(cnt1 + 1, cnt2, pos + 1) + member[pos].part1;
	ll to2 = dfs(cnt1, cnt2 + 1, pos + 1) + member[pos].part2;
	ll to3 = dfs(cnt1, cnt2, pos + 1) + member[pos].part3;

	return std::max({to1, to2, to3});
}

int main()
{
	std::ifstream fin("club.in");
	std::ofstream fout("club.out");

	int t;
	fin >> t;
	while(t--)
	{
		fin >> n;
		for(int i = 1; i <= n; ++i)
			fin >> member[i].part1 >> member[i].part2 >> member[i].part3;
		if(n <= 20)
			fout << dfs(0, 0, 0) << "\n";
		else
		{
			ll ans = 0;
			int a_cnt = 0;
			for(int i = 1; i <= n; ++i)
			{
				if(member[i].part1 > member[i].part2 && a_cnt < n / 2)
				{
					a_cnt++;
					ans += member[i].part1;
				}
				else ans += member[i].part2;
			}
			fout << ans << "\n";
		}
	}
}

