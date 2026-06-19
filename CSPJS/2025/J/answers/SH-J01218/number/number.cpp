#include <bits/stdc++.h>
#define N 15
using namespace std;
typedef long long ll;

string s,ans;
int a[10];
int len;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for (int i = 0;i < len;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int number = s[i] - '0';
			a[number]++;
		}
	}
	ans = "";
	for (int i = 9;i >= 0;i--)
	{
		if (a[i] > 0)
		{
			char x = i + '0';
			for (int j = 1;j <= a[i];j++)
				ans += x;
		}
	}
	cout << ans << endl;
	return 0;
}
