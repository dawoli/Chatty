#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Edge
{
    int u , v , w;
    friend bool operator<(const Edge &x , const Edge &y)
    {
        return x.w < y.w;
    }
}a[1100010] , b[1100010];

int n , m , k , fa[10020] , c[20][10010] , mon[20];
long long ans = 9e18;

int mfind(int x)
{
    if (fa[x] == 0 || fa[x] == x) return fa[x] = x;
    return fa[x] = mfind(fa[x]);
}

void mmerge(int x , int y)
{
    fa[mfind(x)] = mfind(y);
}

long long getans(int sz)
{
    memcpy(b , a , sizeof(a));
    memset(fa , 0 , sizeof(fa));
    sort(b + 1 , b + sz + 1);
    int cnt = 0;
    long long sum = 0;
    for (int i = 1; i <= sz; i++)
    {
        int u = b[i].u , v = b[i].v , w = b[i].w;
        if (mfind(u) != mfind(v))
        {
            //printf("    add:{%d,%d,%d}\n" , u , v , w);
            if (max(u , v) <= n) cnt++;
            sum += w;
            mmerge(u , v);
            if (cnt >= n) return sum;
        }
    }
    return sum;
}

void dfs(int step , int sz , int cnt , long long sum)
{
    //printf("{%d,%d,%d,%lld}\n" , step , sz , cnt , sum);
    if (step > k)
    {
        //for (int i = 1; i <= sz; i++)
        //{
        //    printf("  {%d,%d,%d}\n" , a[i].u , a[i].v , a[i].w);
        //}
        //printf("  %lld\n" , sum + getans(sz , n + cnt));
        ans = min(ans , sum + getans(sz));
        return;
    }
    dfs(step + 1 , sz , cnt , sum);
    for (int i = 1; i <= n; i++)
    {
        a[++sz] = {i , n + step , c[step][i]};
    }
    dfs(step + 1 , sz , cnt + 1 , sum + mon[step]);
}

void solve1()
{
    //printf("solve1:\n");
    int sz = m;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[++sz] = {n + i , j , c[i][j]};
        }
    }
    printf("%lld\n" , getans(sz));
}

int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    scanf("%d%d%d" , &n , &m , &k);
    //printf("%d %d %d\n" , n , m , k);
    //printf("[%d,%d,%d]\n" , n , m , k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d" , &a[i].u , &a[i].v , &a[i].w);
        //printf("%d %d %d\n" , a[i].u , a[i].v , a[i].w);
    }
    //printf("yahaha!\n");
    for (int i = 1; i <= k; i++)
    {
        scanf("%d" , &mon[i]);
        //printf("%d\n" , mon[i]);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d" , &c[i][j]);
            //printf(" %d" , c[i][j]);
        }
        //puts("");
    }
    if (*max_element(mon + 1 , mon + k + 1) == 0)
    {
        solve1();
        return 0;
    }
    dfs(1 , m , 0 , 0);
    printf("%lld\n" , ans);
    return 0;
}
