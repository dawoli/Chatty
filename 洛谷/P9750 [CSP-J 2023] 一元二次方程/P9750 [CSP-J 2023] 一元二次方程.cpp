// Problem URL: https://www.luogu.com.cn/problem/P9750
// Finish Time: 2026/10/2 14:01:08 AC
// Start Time: 2026/10/2 13:47:17
// Category: 数学 模拟

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

string to_frac(int p, int q)
{
	if (q < 0)
	{
		p = -p;
		q = -q;
	}
	int g = __gcd(abs(p), q);
	p /= g;
	q /= g;
	if (q == 1)
		return to_string(p);
	return to_string(p) + "/" + to_string(q);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, M;
	cin >> T >> M;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int d = b * b - 4 * a * c;
		if (d < 0)
		{
			cout << "NO\n";
			continue;
		}
		if (d == 0)
		{
			cout << to_frac(-b, 2 * a) << endl;
			continue;
		}

		int k = 1, r = d;
		for (int d = 2; d * d <= r; ++d)
		{
			while (r % (d * d) == 0)
			{
				r /= d * d;
				k *= d;
			}
		}

		if (r == 1)
		{
			int s = (a > 0 ? 1 : -1);
			cout << to_frac(-b + s * k, 2 * a) << endl;
			continue;
		}

		string q1 = to_frac(-b, 2 * a);
		string q2 = to_frac(k, 2 * abs(a));

		if (q1 != "0")
			cout << q1 << '+';

		if (q2 == "1")
			cout << "sqrt(" << r << ')';
		else if (q2.find('/') == string::npos)
			cout << q2 << "*sqrt(" << r << ')';
		else
		{
			size_t pos = q2.find('/');
			string up = q2.substr(0, pos), down = q2.substr(pos + 1);
			if (up == "1")
				cout << "sqrt(" << r << ")/" << down;
			else
				cout << up << "*sqrt(" << r << ")/" << down;
		}
		cout << endl;
	}
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：较大根不是恒为 (-b+sqrt(d))/(2a)，当 a<0 时
 *   要取 (-b-sqrt(d))/(2a)，即 sgn(a) 要跟着 a 变；delta=0 时
 *   单独处理，不能进分解循环（r 会变成 0 输出 sqrt(0)）。
 * - 关键结论/技巧：把 d 分解为 k^2*r（r 无平方因子），则较大根
 *   可写成 q1 + q2*sqrt(r)，且 q2 = k/(2|a|) 恒为正，无需再判符号；
 *   r==1 说明 d 是完全平方数，两根都有理，直接按有理数输出。
 * - 复杂度：O(T * sqrt(d))，delta 由 M<=1000 限制，足够快。
 */