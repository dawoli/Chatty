#include<bits/stdc++.h>
using namespace std;
long long s[100000000], cnt;
void ha(int n, long long tmp, int l, int num)
{
	if(n < 0) return;
	if(n == 1 || n == 8 || n == 9) return;
	if(n == 0)
	{
		cnt++;
		s[cnt] = tmp;
		return;
	}
	else
	{
		if(l != 0 && num == 0) ha(n - 6, tmp * 10, l + 1, 0);
		if(num == 0)
		{
			ha(n - 2, tmp * 10 + 1, l + 1, 1);
			ha(n - 5, tmp * 10 + 2, l + 1, 2);
			ha(n - 5, tmp * 10 + 3, l + 1, 3);
			ha(n - 4, tmp * 10 + 4, l + 1, 4);
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 1)
		{
			ha(n - 2, tmp * 10 + 1, l + 1, 1);
			ha(n - 5, tmp * 10 + 2, l + 1, 2);
			ha(n - 5, tmp * 10 + 3, l + 1, 3);
			ha(n - 4, tmp * 10 + 4, l + 1, 4);
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 2)
		{
			ha(n - 5, tmp * 10 + 2, l + 1, 2);
			ha(n - 5, tmp * 10 + 3, l + 1, 3);
			ha(n - 4, tmp * 10 + 4, l + 1, 4);
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 3)
		{
			ha(n - 5, tmp * 10 + 3, l + 1, 3);
			ha(n - 4, tmp * 10 + 4, l + 1, 4);
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 4)
		{
			ha(n - 4, tmp * 10 + 4, l + 1, 4);
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 5)
		{
			ha(n - 5, tmp * 10 + 5, l + 1, 5);
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 6)
		{
			ha(n - 6, tmp * 10 + 6, l + 1, 6);
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 7)
		{
			ha(n - 3, tmp * 10 + 7, l + 1, 7);
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 8)
		{
			ha(n - 7, tmp * 10 + 8, l + 1, 8);
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
		if(num == 9)
		{
			ha(n - 6, tmp * 10 + 9, l + 1, 9);
		}
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n % 7 == 0) 
		{
			for(int i = 1; i <= n / 7; i++)
			{
				cout << 8;
			} 
			cout << endl;
		}
		else if(n % 7 == 1) 
		{
			cout << 10;
			for(int i = 1; i < n / 7; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else
		{
			memset(s, 0, sizeof(s));
			ha(n, 0, 0, 0);
			sort(s + 1, s + cnt + 1);
			if(n != 6 && s[1] != 0) 
			{
				for(int i = 1; i <= cnt; i++)
				{
					if(s[i] > 0) 
					{
						cout << s[i] << endl;
						break;
					}
				}
			}
			if(n == 6 && s[1] == 0) cout << s[1] << endl;
			if(n != 6 && s[1] == 0) cout << -1 << endl;
		}
	} 
	return 0;
} 
