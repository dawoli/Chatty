#include<cstdio>
#include<algorithm>
using namespace std;

struct Range
{
    int l , r;
    friend bool operator<(const Range &x , const Range &y)
    {
        return x.r < y.r;
    }
}rg[500010];

struct Node
{
    int id , val;
    friend bool operator<(const Node &x , const Node &y)
    {
        if (x.val != y.val) return x.val < y.val;
        return x.id < y.id;
    }
}v[500010];

int n , k , sz , a[500010] , s[500010];

void solve1()
{
    for (int i = 1; i <= n; i++)
    {
        int val = 0 , pos = -1;
        for (int j = i; j <= n; j++)
        {
            val ^= a[j];
            if (val == k)
            {
                pos = j;
                break;
            }
        }
        //printf("{%d,%d}\n" , i , pos);
        if (pos != -1) rg[++sz] = {i , pos};
    }

}

int searchfor(int lft , int val)
{
    int l = 1 , r = n , ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        //printf("  chk:%d:%d\n" , m , v[m].val);
        if (v[m].val >= val && (v[m].val > val || v[m].id >= lft))
        {
            r = m - 1 , ans = m;
            //printf("    success\n");
        }
        else l = m + 1;// , printf("    fail\n");
    }
    if (v[ans].val != val) return n + 1;
    return ans;
}

void solve2()
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] ^ a[i];
        v[i] = {i , s[i]};
        //printf("%d " , s[i]);
    }
    //puts("");
    sort(v + 1 , v + n + 1);
    //for (int i = 1; i <= n; i++)
    //{
    //    printf("%d %d\n" , v[i].id , v[i].val);
    //}
    for (int i = 1; i <= n; i++)
    {
        int need = k ^ s[i - 1];
        int pos = searchfor(i , need);
        //printf("find%d:{%d,%d}\n" , need , i , pos <= n ? v[pos].id : -1);
        if (pos <= n) rg[++sz] = {i , v[pos].id};
    }
    // sort()
    // for()
    // printf()
}

int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    scanf("%d%d" , &n , &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d" , &a[i]);
    }
    if (n <= 1000) solve1();
    else solve2();
    sort(rg + 1 , rg + sz + 1);
    int ans = 0 , r = 0;
    for (int i = 1; i <= sz; i++)
    {
        while (rg[i].l <= r && i <= sz) i++;
        if (i > sz) break;
        ans++;
        r = rg[i].r;
    }
    printf("%d\n" , ans);
    return 0;
}
