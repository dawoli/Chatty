#include<bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int j = 1; j <= q; j++)
	{
		int cnt = 0;
		string a, b;
		cin >> a >> b;
		bool fl = false;
		int f, e;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] != b[i])
			{
				if(fl == false)
				{
					fl = true;
					f = i;
				}
				e = i;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int k = f-s1[i].size()+1; k <= e+s1[i].size()-1; k++)
			{
				bool f = false;
				for(int l = k; l <= k + s1[i].size()-1; l++)
				{
					if(a[l] != s1[i][l] || b[l] != s2[i][l])
					{
						f = true;
						break;
					}
				}
				if(!f)
				{
					cnt++;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
