#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m;
string s;
int c[510],ttt[510];


int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        ttt[i] = i;
    }
    int ans = 0;
    do
    {
        int fail = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fail >= c[ttt[i]]) fail++;
            else if (s[i] == '0') fail++;
        }
        if (n - fail >= m) ans++;
    }
    while (next_permutation(ttt+ 1,ttt + n + 1));
    cout<< ans << endl;
    return 0;
}
