#include <bits/stdc++.h> 
using namespace std;
#define ll long long

#define mod 998244353

ll calc(ll n, ll c)
{
	ll tmp = 1;
	for (int i = n; i >= n - c + 1; i--)
	{
		tmp *= i;
		tmp %= mod;
	}
	for (int i = q; i >= 1; i--)
	{
		tmp /= i;
		tmp %= mod;
	}
	return tmp;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ll n, q;
	cin >> n >> q;
	string tmp; cin >>tmp;
	ll tmp2, flag = 1, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp2;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if ((tmp[i] - '0') && flag)
		{
			cnt++;
		}
		else 
		{
			flag = 0;
		}
	}
	if (cnt < q)
	{
		cout << 0 <<endl;
	}
	else
	{
		cout << calc(cnt, q) <<endl;
	}
	return 0; 
}
