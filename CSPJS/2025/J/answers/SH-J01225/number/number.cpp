#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int pos = 0;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.length();
	for (int i = 0;i < l;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[++pos] = s[i] - '0';
		}
	}
	sort(a + 1,a + pos + 1,cmp);
	for (int i = 1;i <= pos;i++)
	{
		cout << a[i];
	}
	return 0;
}
