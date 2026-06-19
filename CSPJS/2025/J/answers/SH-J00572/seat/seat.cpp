#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,x = 1,y = 1,w;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> w;
    int cnt = 0;
    for (int i = 2; i <= n * m; i++)
    {
        int a;
        cin >> a;
        cnt += (a > w);
    }
    cnt++;
    for (int i = 2; i <= cnt; i++)
    {
        x++;
        if (x > n) x = 1,y++;
    }
    cout << y << " " << x << endl;
    return 0;
}