// Problem URL: https://www.luogu.com.cn/problem/P2391
// Finish Time: 2026/5/30 11:20:04 AC
// Start Time: 2026/6/6 10:34:38

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m, p, q;
template<typename T = int> class dsu
{
	size_t dsz;
	vector<size_t> fa;
	vector<T> col;
public:
	dsu(const size_t &n): dsz(n), fa(n + 1), col(n + 1, 0)
	{
		for(int i = 1; i <= n; i++)
			fa[i] = i;
	}
	dsu() = default;
	dsu &init(const size_t &n)
	{
		return *this = dsu(n);
	}
	size_t find(const size_t &x)
	{
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool query(const size_t &x, const size_t &y)
	{
		return find(x) == find(y);
	}
	void change_val(const size_t &x, const T &v)
	{
		col[find(x)] = v;
	}
	bool merge(size_t x, size_t y)
	{
		x = find(x), y = find(y);
		if(x == y)
			return false;
		fa[y] = x;
		return true;
	}
	bool merge(size_t x, size_t y, const T &val)
	{
		col[y] = val;
		x = find(x), y = find(y);
		if(x == y)
			return false;
		fa[y] = x;
		return true;
	}
	void linear_merge(size_t x, size_t y)
	{
		for(size_t i = x; i <= y + 1; i++)
		{
			merge(i + 1, i);
		}
	}
	size_t size() const
	{
		return dsz;
	}
	size_t count()
	{
		size_t cnt = 0;
		for(int i = 1; i <= dsz; i++)
			if(fa[i] == i)
				cnt++;
		return cnt;
	}
	T check_val(const size_t &x)
	{
		return col[x];
	}
};
dsu<> d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> p >> q;
	d.init(n + 1);
	for(int i = m; i >= 1; i--)
	{
		int l = ((ll)i * p + q) % n + 1;
		int r = ((ll)i * q + p) % n + 1;
		if(l > r)
			swap(l, r);
		for(int j = d.find(l); j <= r; j = d.find(j))
		{
			d.change_val(j, i);
			d.merge(j + 1, j);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << d.check_val(i) << '\n';
	}
	return 0;
}