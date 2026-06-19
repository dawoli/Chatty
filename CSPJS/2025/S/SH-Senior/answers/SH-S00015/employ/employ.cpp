#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using ll = long long;
const int maxn = 20;
const int mod = 998244353;

int n, m;
int suf[maxn];
int people[maxn];

int bfs(int pos, int get, int a)
{
	if(pos > n) return 0;
	if(get >= m) return 1;
	
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if((a >> n) == 1)
			continue;
		else
		{
			ans += bfs(pos++, get + (people[i] < suf[i]), a + (1 >> n));
			ans %= mod;
		}
	}
	return ans;
}

int main()
{
	std::ifstream fin("employ.in");
	std::ofstream fout("employ.out");


	fin >> n >> m;
	std::string difc;
	fin >> difc;
	for(int i = 1; i <= n; ++i)
		fin >> people[i];
	for(int i = 0; i < n; ++i)
	{
		suf[i + 1] += (difc[i] == '0') + suf[i];
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans += bfs(i, 0,1 << n);
		ans %= mod;
	}
	std::cout << ans;

}
