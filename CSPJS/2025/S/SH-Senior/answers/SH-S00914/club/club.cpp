#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Stud
{
    int id , x , y , z;
}a[100010] , b[100010];

bool cmp1(Stud x , Stud y)
{
    return min(x.x - x.y , x.x - x.z) < min(y.x - y.y , y.x - y.z);
}

bool cmp2(Stud x , Stud y)
{
    return min(x.y - x.x , x.y - x.z) < min(y.y - y.x , y.y - y.z);
}

bool cmp3(Stud x , Stud y)
{
    return min(x.z - x.y , x.z - x.x) < min(y.z - y.y , y.z - y.x);
}

int n;

vector<int> g1 , g2 , g3 , tmp;

void solve1()
{
    //printf("solve1:\n");
    int sz = 0;
    tmp = g1;
    for (int x : g1)
    {
        b[++sz] = a[x];
    }
    sort(b + 1 , b + sz + 1 , cmp1);
    g1.clear();
    for (int i = 1; i <= sz - n / 2; i++)
    {
        if (b[i].y > b[i].z) g2.push_back(b[i].id);
        else g3.push_back(b[i].id);
    }
    for (int i = sz - n / 2 + 1; i <= sz; i++)
    {
        g1.push_back(b[i].id);
    }
}

void solve2()
{
    //printf("solve2:\n");
    int sz = 0;
    tmp = g2;
    for (int x : g2)
    {
        b[++sz] = a[x];
    }
    sort(b + 1 , b + sz + 1 , cmp2);
    g2.clear();
    for (int i = 1; i <= sz - n / 2; i++)
    {
        if (b[i].x > b[i].z) g1.push_back(b[i].id);
        else g3.push_back(b[i].id);
    }
    for (int i = sz - n / 2 + 1; i <= sz; i++)
    {
        g2.push_back(b[i].id);
    }
}

void solve3()
{
    //printf("solve3:\n");
    int sz = 0;
    tmp = g3;
    for (int x : g3)
    {
        b[++sz] = a[x];
    }
    sort(b + 1 , b + sz + 1 , cmp3);
    g3.clear();
    for (int i = 1; i <= sz - n / 2; i++)
    {
        if (b[i].x > b[i].y) g1.push_back(b[i].id);
        else g2.push_back(b[i].id);
    }
    for (int i = sz - n / 2 + 1; i <= sz; i++)
    {
        g3.push_back(b[i].id);
    }
}
/*
void print()
{
    printf("g1:");
    for (auto x : g1) printf("%d " , x);
    puts("");
    printf("g2:");
    for (auto x : g2) printf("%d " , x);
    puts("");
    printf("g3:");
    for (auto x : g3) printf("%d " , x);
    puts("");
    puts("");
}
*/
int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int T;
    scanf("%d" , &T);
    while (T--)
    {
        g1.clear();
        g2.clear();
        g3.clear();
        scanf("%d" , &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d" , &a[i].x , &a[i].y , &a[i].z);
            a[i].id = i;
            if (a[i].x >= max(a[i].y , a[i].z)) g1.push_back(i);// , printf("g1+=%d\n" , i);
            else if (a[i].y >= max(a[i].x , a[i].z)) g2.push_back(i);// , printf("g2+=%d\n" , i);
            else g3.push_back(i);// , printf("g3+=%d\n" , i);
        }
        //print();
        if (g1.size() > n / 2) solve1();
        else if (g2.size() > n / 2) solve2();
        else if (g3.size() > n / 2) solve3();
        //print();
        int ans = 0;
        for (int x : g1) ans += a[x].x;
        for (int x : g2) ans += a[x].y;
        for (int x : g3) ans += a[x].z;
        printf("%d\n" , ans);
    }
    return 0;
}
