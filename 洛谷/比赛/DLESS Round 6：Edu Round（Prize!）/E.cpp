// Problem URL: https://www.luogu.com.cn/contest/340305
// Start Time: 2026/8/8 12:59:45

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const size_t	  MAXN = 2e6 + 6;

template<typename T>
class line_tree_min_delay
{

	struct node
	{
		size_t lt, rt;
		T	   w;
		T	   tag = 0;
	};

	vector<node> e;
public:
	line_tree_min_delay() = default;

	void pushup(size_t u)
	{
		e[u].w = min(e[u * 2].w, e[u * 2 + 1].w);
	}

	void build(size_t u, size_t L, size_t R, const vector<T> &data)
	{
		e[u].lt = L;
		e[u].rt = R;
		if (L == R)
		{
			e[u].w = data[L - 1]; // 修复：使用 data[L - 1]（data 是 0-based）
		}
		else
		{
			size_t M = (L + R) / 2;
			build(u * 2, L, M, data);
			build(u * 2 + 1, M + 1, R, data);
			pushup(u);
		}
	}

	void init(size_t tree_size, const vector<T> &data)
	{
		e.clear();
		e.resize((tree_size + 1) * 4);
		build(1, 1, tree_size, data);
	}

	line_tree_min_delay(size_t tree_size, const vector<T> &data)
	{
		e.resize((tree_size + 1) * 4);
		build(1, 1, tree_size, data);
	}

	// 判断节点区间 [L,R] 是否被查询区间 [l,r] 完全覆盖
	bool InRange(size_t L, size_t R, size_t l, size_t r)
	{
		return (l <= L && R <= r);
	}

	// 判断节点区间 [L,R] 与查询区间 [l,r] 是否无交集
	bool OutRange(size_t L, size_t R, size_t l, size_t r)
	{
		return (R < l || r < L);
	}

	// // 给节点打标记（增加值 x 到区间）
	// void maketag(size_t u, size_t L, size_t R, T x)
	// {
	// 	e[u].tag += x;
	// 	e[u].w += T(R - L + 1) * x;
	// }

	// void pushdown(size_t u, size_t L, size_t R)
	// {
	// 	if (L == R)
	// 		return;
	// 	if (e[u].tag == T(0))
	// 		return; // 只有有标记时才下推
	// 	size_t M = (L + R) / 2;
	// 	maketag(u * 2, L, M, e[u].tag);
	// 	maketag(u * 2 + 1, M + 1, R, e[u].tag);
	// 	e[u].tag = T(0);
	// }

	T query(size_t u, size_t L, size_t R, size_t l, size_t r)
	{
		if (InRange(L, R, l, r))
		{
			return e[u].w;
		}
		if (OutRange(L, R, l, r))
		{
			return T(INT_MAX);
		}
		size_t M = (L + R) / 2;
		// pushdown(u, L, R);
		return min(query(u * 2, L, M, l, r), query(u * 2 + 1, M + 1, R, l, r));
	}

	// void update(size_t u, size_t L, size_t R, size_t l, size_t r, T x)
	// {
	// 	if (InRange(L, R, l, r))
	// 	{
	// 		maketag(u, L, R, x);
	// 		return;
	// 	}
	// 	if (OutRange(L, R, l, r))
	// 		return;
	// 	size_t M = (L + R) / 2;
	// 	pushdown(u, L, R);
	// 	update(u * 2, L, M, l, r, x);
	// 	update(u * 2 + 1, M + 1, R, l, r, x);
	// 	pushup(u);
	// }
};
int						 n;
ll						 ans;
vector<int>				 a;
vector<string>			 b;
line_tree_min_delay<int> t;

auto code_str(const int &a, const int &b)
{
	string s;
	int	   la = 0, lb = 0;
	int	   c = a, d = b;
	while (c != 0)
	{
		la++;
		c /= 10;
	}
	while (d != 0)
	{
		lb++;
		d /= 10;
	}
	int za = 7 - la, zb = 7 - lb;
	while (za--)
		s.append("0");
	s.append(to_string(a));
	while (zb--)
		s.append("0");
	s.append(to_string(b));
	return s;
}

auto decode_str(string s)
{
	int a = 0, b = 0;
	int i = 0;
	while (i < 7)
	{
		a *= 10;
		a += s[i++] - '0';
	}
	while (i < s.length())
	{
		b *= 10;
		b += s[i++] - '0';
	}
	return make_pair(a, b);
}

void solve()
{
	ans = 0;
	cin >> n;
	a.clear();
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		a.push_back(x);
		b.push_back(code_str(x, i));
	}
	sort(b.begin(), b.end());
	t.init(n, a);

	for (int l = 1; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i + l - 1;
			int x = t.query(1, 1, n, i, j);

			auto d = upper_bound(b.begin(), b.end(), code_str(x, j)) - 1;
			int	 p = decode_str(*d).second;
			ans += j - p + 1;
			d += 1;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}