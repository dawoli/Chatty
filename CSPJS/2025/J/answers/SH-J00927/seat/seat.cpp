#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sz = 0,ans,cnt;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[++sz];
    ans = a[1];
    sort(a + 1,a + sz + 1,cmp);
    for (int i = 1; i <= sz; i++)
        if (a[i] == ans)
        {
            cnt = i;
            break;
        }
    int x = cnt / n;
    if (n * x != cnt) x++;
    cout << x << " ";
    ans = cnt % n;
    if (ans == 0) ans = n;
    if (x % 2 == 1) cout << ans;
    else cout << n - ans + 1;
    return 0;
}
