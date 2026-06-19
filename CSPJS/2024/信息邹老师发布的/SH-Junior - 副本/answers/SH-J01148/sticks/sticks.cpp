#include<bits/stdc++.h>
using namespace std;
long long T, n, ans = 0x3f3f3f3f, t, ta, minlen, u, minc;
int mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void f(int x, int a, int len, int check)
{
	if(check == 1 && a == 0)
		return;
	if(x < 0)
		return; 
	if(x == 0)
	{
		if(len + check < minlen)
		{
			ans = a;
			minlen = len + check;
			minc = check;
			u = len;
		}
		else if(len + check == minlen)
		{
			if(minc < check)
			{
				int b = ans;
				for(int k = minc; k <= check; k++)
					b = b * 10 + 8;
				if(a < b)
				{
					ans = a;
					minc = check;
					u = len;
				}
			}
			else if(a < ans)
				ans = a;
		}
		return;
	}
	for(int i = 0; i <= 9; i++)
		f(x - mp[i], a * 10 + i, len, check + 1);
	return;
}
int main()
{
	freopen("sticks1.in", "r", stdin);
	freopen("sticks1.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		ans = 0x3f3f3f3f;
		cin >> n;
		if(n == 1)
		{
			cout << -1 << endl;
			continue;
		}
		t = n % 7;
		ta = n / 7;
		for(int j = 0; j <= ta; j++)
		{
			if(j >= 3)
				break;
			f(t+7*j, 0, ta-j, 0);
		}
		if(ans == 0)
			cout << -1 << endl;
		else
		{
			cout << ans;
			for(int i = 1; i <= u; i++)
				cout << 8;
			cout << endl;
		}
	}
	return 0;
} 
