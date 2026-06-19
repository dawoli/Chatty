#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 5, mod = 1e9 + 7;
ll n, q, pi1[N][N], pi2[N][N], ans, minn, maxn;
bool flag;
string s[N][2], t1, t2;
set<ll> st;
void make1(string s, ll x)
{
	for(int i = 1, j = 0; i < s.size(); i++)
	{
		while(j != 0 && s[i] != s[j])
		{
			j = pi1[x][j - 1];
		}
		if(s[i] == s[j])
		{
			j++;
		}
		pi1[x][i] = j;
	}
}
void make2(string s, ll x)
{
	for(int i = 1, j = 0; i < s.size(); i++)
	{
		while(j != 0 && s[i] != s[j])
		{
			j = pi2[x][j - 1];
		}
		if(s[i] == s[j])
		{
			j++;
		}
		pi2[x][i] = j;
	}
}
void find1(string s, string t, ll x)
{
	st.clear();
	for(int i = 0, j = 0; i < s.size(); i++)
	{
		while(j != 0 && s[i] != t[j])
		{
			j = pi1[x][j - 1];
		}
		if(s[i] == t[j])
		{
			j++;
		}
		if(j >= t.size() && i - j + 1 <= minn && i >= maxn)
		{
			st.insert(i - j + 1);
//			cout << i - j + 1 << " ";
		}
	}
//	cout << endl;
}
void find2(string s, string t, ll x)
{
	for(int i = 0, j = 0; i < s.size(); i++)
	{
		while(j != 0 && s[i] != t[j])
		{
			j = pi2[x][j - 1];
		}
		if(s[i] == t[j])
		{
			j++;
		}
		if(j >= t.size() && st.find(i - j + 1) != st.end())
		{
			ans++;
//			cout << i - j + 1 << " ";
		}
	}
//	cout << endl;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		make1(s[i][0], i);
		make2(s[i][1], i);
	}
	for(int i = 1; i <= q; i++)
	{
		bool flag = 0;
		ans = maxn = minn = 0;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		} 
		for(int j = 0; j < t1.size(); j++)
		{
			if(t1[j] != t2[j])
			{
				if(!flag)
				{
					minn = maxn = j;
					flag = 1;
				}
				else
				{
					maxn = j;
				}
			}
		}
//		cout << maxn << " " << minn << endl;
		for(int j = 1; j <= n; j++)
		{
			find1(t1, s[j][0], j);
			find2(t2, s[j][1], j);
//			cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
