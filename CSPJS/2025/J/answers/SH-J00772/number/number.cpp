#include <bits/stdc++.h>
using namespace std;
string s;
int n = 0, len = 0;
int a[1000010];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	len = s.length();
	for(int i = 0;i < len;i ++)
		if(s[i] >= '0' && s[i] <= '9')
			a[++ n] = (s[i] - '0');
	
	sort(a + 1, a + 1 + n, cmp);
	if(!a[1])
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1;i <= n;i ++)
		cout << a[i];
	return 0;
}
