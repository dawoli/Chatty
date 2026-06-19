#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ull;

const int N = 200010;
const ull P = 13331;

int n, m, q;
string s[N][2];
LL ans;
ull w[2][N], v[2][N];
ull pw[N]; 

int main()
{
	freopen("replace.in", "r", stdin);	
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++ ) cin >> s[i][0] >> s[i][1];
	pw[0] = 1;
	for (int i = 1; i < N; i ++ ) pw[i] = pw[i - 1] * P;
	
	while (q -- )
	{
		ans = 0;
		
		string t[2];
		cin >> t[0] >> t[1];
		m = t[0].length();
		if (t[0].length() != t[1].length()) {puts("0"); continue; }
		int pl = -1, pr;
		for (int i = 0; i < m; i ++ )
			if (t[0][i] != t[1][i])
			{
				if (pl == -1) pl = i;
				pr = i;
			}
		w[0][0] = t[0][0];
		w[1][0] = t[1][0];
		for (int i = 1; i < m; i ++ ) 
			for (int j = 0; j < 2; j ++ )
				w[j][i] = w[j][i - 1] * P + t[j][i];
		int len = pr - pl + 1; 
		ull fx[2] = {w[0][pr] - (pl == 0 ? 0 : w[0][pl - 1] * pw[len]), w[1][pr] - (pl == 0 ? 0 : w[1][pl - 1] * pw[len])};
		
		for (int i = 1; i <= n; i ++ )
		{
			int sz = s[i][0].length();
			if (sz < len) continue;
			if (sz > m) continue;
			v[0][0] = s[i][0][0];
			v[1][0] = s[i][1][0];
			for (int ii = 1; ii < sz; ii ++ ) 
				for (int j = 0; j < 2; j ++ )
					v[j][ii] = v[j][ii - 1] * P + s[i][j][ii];			
					
			for (int l = 0, r = l + len - 1; r < sz; l ++ , r ++ )
			{
				if (l > pl || (sz - (r + 1)) > (m - (pr + 1))) continue;
				
				ull ux[2] = {v[0][r] - (l == 0 ? 0 : v[0][l - 1] * pw[len]), v[1][r] - (l == 0 ? 0 : v[1][l - 1] * pw[len])};
		
				if (!(ux[0] == fx[0] && ux[1] == fx[1])) continue;
				
				ull lx[2] = {l == 0 ? 0 : v[0][l - 1], l == 0 ? 0 : v[1][l - 1]};
				if (lx[0] != lx[1]) continue;
				int tl = pl - l, tr = pl - 1, tlen = tr - tl + 1; 
				ull flx = w[0][tr] - (tl == 0 ? 0 : w[0][tl - 1] * pw[tlen]);
				if (lx[0] != flx) continue;
				
				int tren = sz - 1 - (r + 1) + 1;
				ull rx[2] = {r == sz - 1 ? 0 : v[0][sz - 1] - v[0][r] * pw[tren], r == sz - 1 ? 0 : v[1][sz - 1] - v[1][r] * pw[tren]};
				if (rx[0] != rx[1]) continue;
				tl = pr + 1, tr = tl + tren - 1;
				ull frx = (pr == m - 1 ? 0 : w[0][tr] - w[0][tl - 1] * pw[tren]);
				if (rx[0] != frx) continue;
				
				ans ++ ;
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}
