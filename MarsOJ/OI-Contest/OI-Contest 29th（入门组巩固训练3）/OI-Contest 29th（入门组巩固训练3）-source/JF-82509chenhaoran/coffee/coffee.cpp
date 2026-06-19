#include <bits/stdc++.h>
using namespace std;
string s[9][9];
long long cnt[10];
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        long long ans = 0 ,e = 0;
        memset(cnt,0,sizeof(cnt));
        for(int x = 1;x <= 5;x++)
        {
            long long f = 0;
            for(int y = 1;y <= 8;y++)
            {
                cin >> s[x][y];
                if(s[x][y] == "math")
                {
                    f++;
                }
            }
            cnt[x] = f;
            e += f;
        }
        long long aa,bb;
        cin >> aa >> bb;
        for(int j = bb;j <= (bb + aa) - 1;j++)
        {
            ans += cnt[j%7];
        }
        cout << ans << endl;
    }
    return 0;
}