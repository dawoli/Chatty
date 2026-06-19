#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int next1[N][100];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin >> n >> q;
	string s[N][3],t[N][3];
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
		for (int k = 0,j = 0;k < s[i][1].length();k++)
		{
			while (j > 0 && s[i][1][j] != s[i][1][k])
			{
				j = next1[i][j-1];
			}
			if (s[i][1][j] == s[i][1][k]) j++;
			next1[i][k] = j;
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> t[i][1] >> t[i][2];
		int ans = 0;
		for (int j = 1;j <= n;j++)
		{
			for (int k = 0,m = 0;k < t[i][1].length();k++)
			{
				while (m > 0 && s[j][1][m] != t[i][1][k])
				{
					m = next1[j][m-1];
				}
				if (s[j][1][m] == t[i][1][k]) m++;
				if (m == s[j][1].length())
				{
					int pos = k-m+1;
					bool t1 = true;
					for (int p = 0;p < t[i][2].length();p++)
					{
						if (p >= pos && p <= k)
						{
							if (t[i][2][p] != s[j][2][p-pos])
							{
								t1 = false;
								break;
							}
						}
						else
						{
							if (t[i][2][p] != t[i][1][p])
							{
								t1 = false;
								break;
							}
						}
					}
					if (t1) ans++;
					m = next1[j][m-1];
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
