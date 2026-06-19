#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 998244353;
int n , cnt , a[5010];

void dfs(int step , int sum , int mx)
{
    if (step > n)
    {
        cnt += (sum > 2 * mx);
        return;
    }
    dfs(step + 1 , sum + a[step] , max(mx , a[step]));
    dfs(step + 1 , sum , mx);
}

void solve1()
{
    dfs(1 , 0 , 0);
    printf("%d\n" , cnt);
}

void solve2()
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * 2ll % mod;
    }
    ans = ((ans - 1 - n - n * (n - 1) / 2) % mod + mod) % mod;
    printf("%d\n" , ans);
}

int f[5010][10010];
int tot[10010];

void solve3()
{
    int MX = *max_element(a + 1 , a + n + 1) * 2 + 2;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = a[i]; k <= MX + a[i]; k++)
            {
                f[i][min(k , MX)] += f[j][k - a[i]];
                f[i][min(k , MX)] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2 * a[i] + 1; j <= MX; j++)
        {
            ans += f[i][j];
            ans %= mod;
        }
    }
    printf("%d\n" , ans);
}

void solve4()
{
    int MX = *max_element(a + 1 , a + n + 1) * 2 + 2;
    f[0][0] = 1;
    tot[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = a[i]; k <= MX + a[i]; k++)
        {
            f[i][min(k , MX)] += tot[k - a[i]];
            f[i][min(k , MX)] %= mod;
        }
        for (int k = a[i]; k <= MX; k++)
        {
            tot[k] += f[i][k];
            tot[k] %= mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2 * a[i] + 1; j <= MX; j++)
        {
            ans += f[i][j];
            ans %= mod;
        }
    }
    printf("%d\n" , ans);
}

void trysolve34()
{
    int MX = *max_element(a + 1 , a + n + 1) * 2 + 2;
    if (1ll * n * n * MX <= 1e7) solve3();
    else solve4();
}

int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d" , &a[i]);
    }
    sort(a + 1 , a + n + 1);
    if (n <= 20) solve1();
    else if (*max_element(a + 1 , a + n + 1) == 1) solve2();
    else trysolve34();
    return 0;
}
