#include <bits/stdc++.h>
#define LL long long
using namespace std;
int t,n;
string f[1005];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	f[2] = "1",f[3] = "7";
	for (int i = 4; i <= 1000; i++)
	{
		string s = f[i - 2];
		s += '1';
		for (int j = 3; j <= 7; j++)
		{
			if (i - j <= 1 && i - j != 0) continue;
			string dd = f[i - j];
			if (j == 3) dd += '7';
			else if (j == 4) dd += '4';
			else if (j == 5) dd += '2';
			else if (j == 6)
			{
				if (i - j != 0) dd += '0';
				else dd += '6';
			}
			else dd += '8';
			if (s.size() > dd.size()) s = dd;
			else if (s.size() < dd.size()) continue;
			for (int k = 0; k < s.size(); k++)
				if (dd[k] > s[k]) break;
				else if (dd[k] < s[k]) s = dd;  
		}
		f[i] = s;
//		if (i <= 100) cout << f[i] <<endl;
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1)
		{
			cout << -1 <<endl;
			continue;
		} 
		if (n <= 1000) cout << f[n] << endl;
		else
		{
			int modd = n % 7;
			if (n % 7 == 0) cout << "888",n -= 21;
			else if (n % 7 == 1) cout << "108",n -= 15;
			else if (n % 7 == 2) cout << "188",n -= 16;
			else if (n % 7 == 3) cout << "200",n -= 17;
			else if (n % 7 == 4) cout << "208",n -= 18;
			else if (n % 7 == 5) cout << "288",n -= 19;
			else if (n % 7 == 6) cout << "688",n -= 20;
			for (int i = 1; i <= n / 7; i++) putchar('8');
			puts("");
		}
	}
	return 0;
}
//1088888888888
//1888888888888
//2008888888888
//2088888888888
//2888888888888
//8088888888888
//8888888888888
