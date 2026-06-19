#include <bits/stdc++.h>
using namespace std;

bool t[600];
int n,m;
int ans = 0;
vector <int> a;
string s;

void dfs(vector <int> a,int start)
{
	if (start == n+1)
	{
		int cnt = 0,cnt1 = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i-1] == '1')
			{
				if (cnt1 < a[i])
				{
					cnt++;
					cnt1 = 0;
				}
				else
				{
					cnt1++;
				}
			}
			else
			{
				cnt1++;
			}
		}
		if (cnt == m) ans++;
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!t[i]) 
		{
			a.push_back(i);
			t[i] = true;
			dfs(a,start+1);
			a.pop_back();
			t[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> s;
	a.resize(n+10);
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	dfs(a,1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
