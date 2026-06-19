#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005] = {0},b[1000005],c,d,n,m,mx;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			c = int(s[i]) - 48;
			a[c]++;
			if(c >= mx)
			{
				mx = c;
			}
		}
	}
	for (int i = mx; i > 0; i--)
	{
		if(a[i] != 0)
		{
			for (int j = 1; j <= a[i]; j++)
			{
				cout << i;
			}
		}
	}
	return 0;
}
