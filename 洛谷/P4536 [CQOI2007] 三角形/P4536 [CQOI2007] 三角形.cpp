// Problem URL: https://www.luogu.com.cn/problem/P4536 [CQOI2007] 三角形
// Start Time: 2026/10/5 12:44:34

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

string s, up;
vector<string> ans;

void one()
{
	if (s[1] == 4)
		cout << "T1\nT2\nT3\n";
	else 
		cout <<"T4\n";
}

void two()
{
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	up = s.substr(0, max(int(s.length()) - 3, 1));
	if (s.length() == 2)
		one();
	else if (s.length() == 3)
		two();
	return 0;
}