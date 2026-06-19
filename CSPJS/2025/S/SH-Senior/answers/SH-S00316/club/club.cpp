#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int num,id,id1,id2;
};

bool cmp(node a,node b)
{
    return a.num > b.num;
}

int a[100010][4];
node c[100010];
int cnt[4];

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            int x,y,z;
            cin >> x >> y >> z;
            a[i][1] = x;
            a[i][2] = y;
            a[i][3] = z;
            c[i].id = i;
            if (x >= y && y >= z)
            {
                c[i].num = x - y;
                c[i].id1 = 1;
                c[i].id2 = 2;
            }
            else
            {
                if (x >= z && z >= y)
                {
                    c[i].num = x - z;
                    c[i].id1 = 1;
                    c[i].id2 = 3;
                }
                else
                {
                    if (y >= x && x >= z)
                    {
                        c[i].num = y - x;
                        c[i].id1 = 2;
                        c[i].id2 = 1;
                    }
                    else
                    {
                        if (y >= z && z >= x)
                        {
                            c[i].num = y - z;
                            c[i].id1 = 2;
                            c[i].id2 = 3;
                        }
                        else
                        {
                            if (z >= y && y >= x)
                            {
                                c[i].num = z - y;
                                c[i].id1 = 3;
                                c[i].id2 = 2;
                            }
                            else
                            {
                                c[i].num = z - x;
                                c[i].id1 = 3;
                                c[i].id2 = 1;
                            }
                        }
                    }
                }
            }
        }
        sort(c + 1,c + n + 1,cmp);
        cnt[1] = 0;
        cnt[2] = 0;
        cnt[3] = 0;
        long long ans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (cnt[c[i].id1] >= n / 2)
            {
                ans += a[c[i].id][c[i].id2];
                cnt[c[i].id2]++;
            }
            else
            {
                ans += a[c[i].id][c[i].id1];
                cnt[c[i].id1]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
