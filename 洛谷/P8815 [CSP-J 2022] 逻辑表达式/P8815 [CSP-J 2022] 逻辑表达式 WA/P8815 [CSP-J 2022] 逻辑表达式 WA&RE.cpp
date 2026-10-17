// Problem URL: https://www.luogu.com.cn/problem/P8815 [CSP-J 2022] 逻辑表达式
// Finish Time: 2026/10/5 14:12:59 WA/RE 10pts
// Start Time: 2026/10/5 13:19:15

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

string		s;
int			cnt1 = 0, cnt2 = 0;
stack<char> k;

bool highpro(const char &c1, const char c2)
{
	if (c2 == '&' && c1 == '|')
		return false;
	return true;
}

auto invert(string v)
{
	stack<char> st;
	string		res;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == '0' || v[i] == '1')
			res.append(to_string(v[i]));
		else if (v[i] == ')')
		{
			while (st.top() != '(')
			{
				res.append(to_string(st.top()));
				st.pop();
			}
			st.pop();
		}
		else if (v[i] == '(' || st.empty() || highpro(v[i], st.top()))
			st.push(v[i]);
		else
		{
			while (!st.empty())
			{
				res.append(to_string(st.top()));
				st.pop();
			}
			st.push(v[i]);
		}
	}
	while (!st.empty())
	{
		res.append(to_string(st.top()));
		st.pop();
	}
	return res;
}

char _and(const char &x, const char &y)
{
	if (x == '0')
	{
		cnt1++;
		return '0';
	}
	else if (y == '1')
		return '1';
	else
		return '0';
}

char _or(const char &x, const char &y)
{
	if (x == '1')
	{
		cnt2++;
		return '1';
	}
	else if (y == '1')
		return '1';
	else
		return '0';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, s);
	s = invert(s);
	for (const auto &i : s)
	{
		if (i == '0' || i == '1')
			k.push(i);
		else if (i == '&')
		{
			const auto x = k.top();
			k.pop();
			const auto y = k.top();
			k.pop();
			k.push(_and(y, x));
		}
		else if (i == '|')
		{
			const auto x = k.top();
			k.pop();
			const auto y = k.top();
			k.pop();
			k.push(_or(y, x));
		}
	}
	cout << k.top() << endl
		 << cnt1 << " " << cnt2 << endl;
	return 0;
}