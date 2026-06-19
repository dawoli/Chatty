#include <iostream>
#include <algorithm>
using namespace std;

int a[1000010];

bool cmp(int a, int b)
{
	return (a > b);
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] > '9' || s[i] < '0')
			continue;
		a[++cnt] = s[i] - '0';
	}
	sort(a + 1, a + cnt + 1, cmp);
	if(a[1] == 0)
		cout << 0 << endl;
	else
	{
		for(int i = 1; i <= cnt; i++)
			cout << a[i];
	}
	cout << endl;
	return 0;
}
