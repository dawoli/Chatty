#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, ans;
string reff[MAXN][5] = {};
int reflen[MAXN] = {};
int refbpos[MAXN][5] = {};
string t[3] = {};
int tbpos[5] = {};

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> reff[i][1] >> reff[i][2];
		// 找到ref[i][1]的b，得出b前面有几位，b后面有几位 
		reflen[i] = reff[i][1].length();
		for (int j = 0; j < reflen[i]; j++)
		{
			if (reff[i][1][j] == 'b')
			{
				refbpos[i][1] = j; // b前 
				refbpos[i][2] = reflen[i] - j - 1; // b后 
			}
		}
	}
	
	for (int i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> t[1] >> t[2];
		for (int r = 1; r <= t[1].length(); r++)
		{
			if (t[1][r] == 'b')
			{
				tbpos[1] = r;
				tbpos[2] = t[1].length() - r - 1;
			}
		}
		for (int r = 1; r <= n; r++)
		{
			if (reflen[i] <= t[1].length() && tbpos[1] - refbpos[i][1] >= 0 && tbpos[2] - refbpos[i][2] <= 0)
			{
				ans++;		
			}
		}
		cout << ans << endl;
	}
	return 0;
}
