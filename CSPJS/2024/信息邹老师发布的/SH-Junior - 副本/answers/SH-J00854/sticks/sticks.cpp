#include <bits/stdc++.h>
using namespace std;
#define int long long

int t;
int n;
string ans = "";
string p;
string a;
bool b;

int st[15] = {6, 2, 5, 1000000, 4, 1000000, 6, 3, 7, 1000000};
string init[30];

void com(string now)
{
	if(now.size() < ans.size())
	{
		ans = now;
		b = true;
		return;
	}
	for(int i = 0; i < now.size(); i++)
	{
		if(now[i] > ans[i]) return;
		else if(now[i] < ans[i])
		{
			ans = now;
			b = true;
			return;
		}
	}
}

void dfs(int num, string now)
{
	if(now.size() > ans.size()) return;
	if(num==0)
	{
		com(now);
		return;	
	}
	for(char i = '0'; i <= '8'; i++)
	{
//		cout << now << ' '  << num  << '!' << i << ' ' << num-st[i-'0'] << endl;
		if(st[i-'0'] <= num)
		{
			dfs(num-st[i-'0'], now+i);
		}
	}
}

signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= 100005 / 2; i++)
	{
		p += '9';
	}
	for(int n = 1; n <= 20; n++)
	{
		ans = p;
		b = false;
		for(int i = 1; i <= 9; i++)
		{
			if(n-st[i] < 0)continue;
			string a = "";
			a+=char(i+'0');
			dfs(n - st[i], a);
		}
		if(!b) init[n] = -1;
		else init[n] = ans;
	}
//	for(int n = 1; n <= 20; n++)
//	{
//		cout << n << ' ' << init[n] << endl;
//	}
	while(t--)
	{
		cin >> n;
		if(n==1)
		{
			cout << -1 << endl;
			continue;
		}
		int cnt = 0;
		while(n > 20)
		{
			n-=7;
			cnt++;
		}
		cout << init[n];
		for(int i = 1; i <= cnt; i++)
		{
			cout << 8;
		}
		cout << endl;
	}
	return 0;
}
