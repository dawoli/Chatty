#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 508, MOD = 998244353;
long long n, m, c[MAXN], ans, cnt;
bool flag = 1;
char s[MAXN];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m;
    int k = n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if(s[i] == 0)
            flag = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    if(flag)
    {
        ans = 1, cnt = 0;
        for(long long i = n; i >= 1; i--)
        {
            if(cnt == m)
                return cout << ans % MOD, 0;
            ans = ans * i % MOD;
            cnt++;
        }
    }
	return 0;
}
