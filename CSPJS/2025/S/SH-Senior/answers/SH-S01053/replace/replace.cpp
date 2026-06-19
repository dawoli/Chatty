#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string a,b;
        cin >> a >> b;
        mp[a] = b;
    }
    while (q--)
    {
        string s,t;
        cin >> s >> t;
        int k = s.size(),ans = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = i; j < k; j++)
            {
                string lingshi = s;
                string tt = "";
                for (int r = i; r <= j; r++) tt += s[r];
                if (mp.count(tt))
                {
                    string ti = mp[tt];
                    int inde = 0;
                    for (int r = i; r <= j; r++)
                    {
                        lingshi[r] = ti[inde];
                        inde++;
                    }
                }
                if (lingshi == t) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
