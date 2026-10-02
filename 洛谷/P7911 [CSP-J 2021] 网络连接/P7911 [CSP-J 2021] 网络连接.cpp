// Problem URL: https://www.luogu.com.cn/problem/P7911
// Finish Time: 2026/10/2 14:44:44 AC
// Start Time: 2026/10/2 14:23:44

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

bool check_num(const string &s, ll low, ll high)
{
	if (s.empty())
	{
		return false;
	}
	if (s.size() > 1 && s[0] == '0')
	{
		return false;
	}
	ll val = 0;
	for (char ch : s)
	{
		if (ch < '0' || ch > '9')
		{
			return false;
		}
		val = val * 10 + (ch - '0');
		if (val > high)
		{
			return false;
		}
	}
	return val >= low && val <= high;
}

bool is_valid(const string &ad)
{
	int dots = 0, cols = 0;
	for (char ch : ad)
	{
		if (ch == '.')
		{
			dots++;
		}
		else if (ch == ':')
		{
			cols++;
		}
		else if (ch < '0' || ch > '9')
		{
			return false;
		}
	}
	if (dots != 3 || cols != 1)
	{
		return false;
	}
	size_t		   col = ad.find(':');
	vector<string> seg;
	string		   cur;
	for (size_t i = 0; i < col; i++)
	{
		if (ad[i] == '.')
		{
			seg.push_back(cur);
			cur.clear();
		}
		else
		{
			cur.push_back(ad[i]);
		}
	}
	seg.push_back(cur);
	if (seg.size() != 4)
	{
		return false;
	}
	for (const string &s : seg)
	{
		if (!check_num(s, 0, 255))
		{
			return false;
		}
	}
	return check_num(ad.substr(col + 1), 0, 65535);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<string, int> server;
	for (int i = 1; i <= n; i++)
	{
		string op, ad;
		cin >> op >> ad;
		if (!is_valid(ad))
		{
			cout << "ERR\n";
			continue;
		}
		if (op == "Server")
		{
			if (server.count(ad))
			{
				cout << "FAIL\n";
			}
			else
			{
				server[ad] = i;
				cout << "OK\n";
			}
		}
		else if (server.count(ad))
		{
			cout << server[ad] << '\n';
		}
		else
		{
			cout << "FAIL\n";
		}
	}

	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：
 *   · 前导 0 判断：段长为 1 时 "0" 合法，否则首字符为 '0' 即非法（"00"、"01"）。
 *   · 空段、非法字符（既非数字也非 . :）都要判非法，不能只数分隔符。
 *   · 段范围：a.b.c.d 是 0~255，端口 e 是 0~65535，别写反或共用同一上限。
 *   · 客户机合法地址只能查服务机表，不把自己登记进表；查无匹配输出 FAIL（不是 ERR）。
 * - 关键结论/技巧：
 *   · 抽一个 check_num(s, low, high) 统一处理「非空 + 无前导 0 + 纯数字 + 范围」，ip 四段与端口复用，
 *     避免复制粘贴范围判断。读数字时发现 val > high 立即 return false，天然防 long long 溢出。
 *   · 先统计 '.' 数与 ':' 数（必须 3 和 1），再按冒号位置把字符串切成 ip 与 port，ip 再按点切 4 段，
 *     结构性错误一步筛掉，比逐字符状态机直观。
 *   · Server 用 map<string,int> 登记地址到编号做去重；Client 只查 count，首四个测试点全合法即可过，
 *     但前导 0 / 空段 / 端口越界这类数据必须覆盖。
 * - 复杂度：O(n log n + n * len)，len ≤ 25，n ≤ 1000。
 */