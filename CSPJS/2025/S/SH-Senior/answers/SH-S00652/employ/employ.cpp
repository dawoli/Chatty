#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[505],x,n;
int A(int a,int b)
{
	long long sum = 1;
	for(int i = n;i >= a - b;i--)
	{
		sum = sum * i % mod;
	}
	return sum;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	bool f1 = 1,f2 = 1;
	int num = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '0')
			f2 = 0;
		else if(s[i] == '1')
			f1 = 0;
		num = num + (s[i] - '0');
	}
	if(!f2 && m == n)
	{
		cout << 0;
		return 0;
	}
	else if(f2)
	{
		long long sum = 1;
		for(int i = 1;i <= n;i++)
		{
			sum = sum * i % mod;
		}
		cout << sum << "\n";
	}
	else if(f1)
	{
		cout << 0;
		return 0;
	}
	else if(num < m)
	{
		cout << 0;
		return 0;
	}
	else
	{
		sort(c + 1,c + n + 1);
		int lst = 0;
		long long ans = 1;
		int y = n;
		for(int i = 0;i < s.size();i++)
		{
			if(s[i] == '0')
			{
				for(int j = 1;j <= n;j++)
				{
					if(c[j] <= x)
						y--;
					else
						break;
				}
				ans = ans * A(y,min(y,i - lst + 1)) % mod;
				x++;
				lst = i;
			}
		}
		cout << ans;
	}
	return 0;
}
