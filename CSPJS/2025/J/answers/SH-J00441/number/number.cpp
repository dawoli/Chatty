#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000001];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	s = ' ' + s;
	int cnt = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cnt += 1;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; ++i)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	/*
	上海2号线蟠祥路·国家会计学院站今日开通运营！ 
	（有趣的灵魂）
	*/
	
	return 0;
}
