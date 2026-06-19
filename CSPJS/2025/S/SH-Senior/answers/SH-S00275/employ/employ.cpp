#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 9;
const long long mod = 998244353;
int n, m, s[_], c[_];
bool check1()
{
	for(int i = 1;i <= n;i++)
		if(!s[i])
			return false;
	return true;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		char c;
		cin >> c;
		s[i] = c == '1';
	}
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	if(n <= 10)
	{
		int ans = 0;
		vector<int> v;
		for(int i = 1;i <= n;i++)
			v.push_back(i);
		do{
			int cnt = 0, nw = 0;
			for(int i = 1;i <= n;i++)
			{
				if(nw >= c[v[i - 1]])
				{
					nw++;
					continue;
				}
				if(!s[i])
				{
					nw++;
					continue;
				}
				cnt++;
			}
			ans = (ans + (cnt >= m)) % mod;
		}while(next_permutation(v.begin(), v.end()));
		cout << ans;
	}
	else if(check1())
	{
		long long ans = 1;
		for(int i = 1;i <= n;i++)
			ans = (ans * i) % mod;
		cout << ans;
	}
	else
		cout << 0;
	
	return 0;
}
