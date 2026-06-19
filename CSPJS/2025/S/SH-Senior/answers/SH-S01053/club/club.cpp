#include <bits/stdc++.h>
using namespace std;

int a[100010],b[100010],c[100010],n;
int f[100010],ans;

void dfs(int now)
{
    if (now > n)
    {
        int c1 = 0,c2 = 0,c3 = 0,sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (f[i] == 1) c1++,sum += a[i];
            if (f[i] == 2) c2++,sum += b[i];
            if (f[i] == 3) c3++,sum += c[i];
        }
        if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2)
        {
            ans = max(ans,sum);
        }
        return;
    }
    f[now] = 1;
    dfs(now + 1);
    f[now] = 2;
    dfs(now + 1);
    f[now] = 3;
    dfs(now + 1);
}

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        int c1 = 0,c2 = 0,c3 = 0;
        bool check1 = 0,check2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] != 0) check1 = check2 = 1;
            if (c[i] != 0) check1 = 1;
        }
        if (!check1)
        {
            sort(a + 1,a + n + 1,cmp);
            for (int i = 1; i <= n / 2; i++)
            {
                ans += a[i];
            }
        }
        else dfs(1);
        cout << ans << endl;
    }

    return 0;
}
