#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int w[N];
int T;
int dp[N];
int redo[N], blueo[N];
int cntr, cntb;
LL ans;

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> w[i];
		
		ans = 0;
		for (LL state = 0; state < (1LL << n); state ++ )
		{
			cntr = 0, cntb = 0;
			for (int j = 0; j < n; j ++ )
			    if (state >> j & 1) redo[ ++ cntr] = w[j + 1];
			    else blueo[ ++ cntb] = w[j + 1];
			
			LL res = 0;
			for (int i = 2; i <= cntr; i ++ )
			    if (redo[i] == redo[i - 1])
			        res += redo[i];
			for (int i = 2; i <= cntb; i ++ )
			    if (blueo[i] == blueo[i - 1])
				    res += blueo[i];
			ans = max(ans, res);		 
		}
		
		cout << ans << endl;
	}
    return 0;	
} 
