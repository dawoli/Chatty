// Problem URL: https://www.luogu.com.cn/problem/P7113 [NOIP2020] 排水系统
// Finish Time: 2026/10/5 16:44:25 WA 60pts
// Start Time: 2026/10/5 16:10:29

#ifndef DEBUG
#define NDEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

struct frac
{
	pii val;

	frac(int numerator = 0, int denominator = 1)
	{
		set(numerator, denominator);
	}

	void simp()
	{
		set(val.first, val.second);
	}

	frac operator+(const frac &other) const
	{
		return frac(
			1LL * val.first * other.val.second + 1LL * other.val.first * val.second,
			1LL * val.second * other.val.second);
	}

	frac operator-(const frac &other) const
	{
		return frac(
			1LL * val.first * other.val.second - 1LL * other.val.first * val.second,
			1LL * val.second * other.val.second);
	}

	frac operator*(const frac &other) const
	{
		return frac(
			1LL * val.first * other.val.first,
			1LL * val.second * other.val.second);
	}

	frac operator/(const frac &other) const
	{
		assert(other.val.first != 0);
		return frac(
			1LL * val.first * other.val.second,
			1LL * val.second * other.val.first);
	}

	frac &operator+=(const frac &other)
	{
		*this = *this + other;
		return *this;
	}

	frac &operator-=(const frac &other)
	{
		*this = *this - other;
		return *this;
	}

	frac &operator*=(const frac &other)
	{
		*this = *this * other;
		return *this;
	}

	frac &operator/=(const frac &other)
	{
		*this = *this / other;
		return *this;
	}

	bool operator==(const frac &other) const
	{
		return val == other.val;
	}
private:
	void set(int numerator, int denominator)
	{
		assert(denominator != 0);
		if (denominator < 0)
		{
			numerator	= -numerator;
			denominator = -denominator;
		}

		int a = numerator < 0 ? -numerator : numerator;
		int b = denominator;
		while (b != 0)
		{
			int remainder = a % b;
			a			  = b;
			b			  = remainder;
		}

		numerator /= a;
		denominator /= a;
		assert(numerator >= numeric_limits<int>::min() && numerator <= numeric_limits<int>::max());
		assert(denominator <= numeric_limits<int>::max());
		val = pii(static_cast<int>(numerator), static_cast<int>(denominator));
	}
} c[MAXN];

int			n, m, in[MAXN];
vector<int> e[MAXN];

void kahn()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0)
		{
			q.push(i);
			c[i] = 1;
		}
	while (!q.empty())
	{
		const auto u = q.front();
		q.pop();
		for (const auto &v : e[u])
		{
			in[v]--;
			if (in[v] == 0)
				q.push(v);
			c[v] += c[u] / e[u].size();
		}
		if (e[u].size() != 0)
			c[u] = 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef DEBUG
	freopen("P7113_7.in", "r", stdin);
	freopen("P7113_7.out", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		while (x--)
		{
			int y;
			cin >> y;
			e[i].push_back(y);
			in[y]++;
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	cout << in[i] << " ";
	// cout << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << e[i].size() << " ";
	// cout << endl;
	kahn();
	for (int i = 1; i <= n; i++)
		if (e[i].size() == 0)
			cout << c[i].val.first << " " << c[i].val.second << endl;
	return 0;
}