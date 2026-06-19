#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 998244353;

int n , m , lim[510];
bool f[510];

int a[20];

void solve1()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    int ans = 0;
    do
    {
        int lst = 0 , cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            //printf(" %d[%d:%d]:{%d,%d}\n" , i , a[i] , lim[a[i]] , lst , cnt);
            if (!f[i]) lst++;
            else
            {
                if (lst < lim[a[i]])
                {
                    //printf("  success\n");
                    cnt++;
                }
                else lst++;
            }
        }
        //printf("ans+=%d\n" , cnt >= m);
        ans += (cnt >= m);
    } while (next_permutation(a + 1 , a + n + 1));
    printf("%d\n" , ans);
}

void solve2()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (lim[i] > 0);
    }
    if (cnt < m)
    {
        puts("0");
        return;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = 1ll * ans * i % mod;
    }
    printf("%d\n" , ans);
}

int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    bool flag2 = true;
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d" , &f[i]);
        if (!f[i]) flag2 = false;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d" , &lim[i]);
    }
    if (n <= 10) solve1();
    else if (flag2) solve2();
    else puts("0");
    return 0;
}
