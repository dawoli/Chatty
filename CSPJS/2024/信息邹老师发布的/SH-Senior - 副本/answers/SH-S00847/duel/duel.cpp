#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[100010] , n;
bool f[100010];

int Find(int st , int x)
{
    int l = st , r = n , ans = n + 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        while (f[m] && m <= n) m++;
//        printf("in\"Find()\":{l=%d,r=%d,m=%d,preans=%d}\n" , l , r , m , ans);
        if (m > r) return ans;
        if (a[m] > x)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
//    	printf("find:>%d\n" , a[i]);
        int pos = Find(i + 1 , a[i]);
        if (pos > n) break;
        f[pos] = true;
        ans--;
    }
    cout << ans << endl;
    return 0;
}
