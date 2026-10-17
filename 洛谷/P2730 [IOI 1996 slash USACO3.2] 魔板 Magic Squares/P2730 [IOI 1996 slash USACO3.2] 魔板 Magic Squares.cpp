// Problem URL: https://www.luogu.com.cn/problem/P2730
// Finish Time: 2026/10/3 16:25:07 AC
// Start Time: 2026/10/3 15:54:12

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const string		   fail = "FAIL";

string						  a;
unordered_map<string, string> m;
queue<string>				  q;

void A(string x)
{
	string y = x;
	for (int i = 0; i < 4; i++)
	{
		char x1	 = x[i];
		x[i]	 = x[7 - i];
		x[7 - i] = x1;
	}
	if (m.find(x) == m.end())
	{
		q.push(x);
		m[x] = m[y] + 'A';
	}
	return;
}

void B(string x)
{
	string y = x;
	x[0] = y[3], x[1] = y[0], x[2] = y[1], x[3] = y[2], x[4] = y[5], x[5] = y[6], x[6] = y[7], x[7] = y[4];
	if (m.find(x) == m.end())
	{  
		q.push(x);
		m[x] = m[y] + 'B';
	}
	return;
}

void C(string x)
{
	string y = x;
	x[1] = y[6], x[2] = y[1], x[5] = y[2], x[6] = y[5];
	if (m.find(x) == m.end())
	{
		q.push(x);
		m[x] = m[y] + 'C';
	}
	return;
}

auto bfs()
{
	q.push("12345678");
	m["12345678"] = "";
	while (!q.empty())
	{
		A(q.front());
		B(q.front());
		C(q.front());
		if (m.find(a) != m.end())
		{
			return m[a];
		}
		q.pop();
	}
	return fail;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 8; i++)
	{
		char a1;
		cin >> a1;
		a += a1;
		if (i != 7)
			getchar();
	}
	auto ans = bfs();
	cout << ans.size() << endl
		 << ans << endl;
	return 0;
}