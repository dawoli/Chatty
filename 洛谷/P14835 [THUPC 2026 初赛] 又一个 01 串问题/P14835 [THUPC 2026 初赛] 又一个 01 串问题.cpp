// Problem URL: https://www.luogu.com.cn/problem/P14835 [THUPC 2026 初赛] 又一个 01 串问题
// Start Time: 2026/10/20 17:59:09

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e5 + 5;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int			 n = s.size();
		bitset<MAXN> mn;
		mn.flip();
		for (int i = 0; i <= n; i++)
		{
			bitset<MAXN> a(s.substr(0, i)), b(s.substr(i, n - i));
			// ! 下面这一段会因为bitset没有定义+运算符报错
			// if (a + b < mn)
			// 	mn = a + b;
		}
		cout << mn << endl;
	}
	return 0;
}

// * 老师对这个代码的评价：
// * substr 把"子序列"当"子串"，
// ! a + b 用 operator+编译错误bitset 无 +，需手写二进制加法，
// ! a + b < mn 的 <语义错误bitset 的 < 非数值大小比较，
// 双层 O(n²) 超时n 总和 5e5，
// ! cout << mn输出错误顺序/前导0不符合"二进制形式"要求

/*
 * 经验总结：
 * - 容易错的地方：把"子序列"当"子串"；用 bitset 当大数（没有 +、< 也不是数值比较）；
 *   枚举切点 × substr 是 O(n²)；输出的是低位在前的位串。
 * - 关键结论/技巧：每个 1 的权重是 2^(它在本子序列中后面的元素数)；
 *   找分界 pos（第一个 s[pos]='1' 且 n-pos <= 已见 1 的个数），前段 1 拼成 s1、后段原样作 s2，手写二进制加法。
 * - 复杂度：O(n)
 */