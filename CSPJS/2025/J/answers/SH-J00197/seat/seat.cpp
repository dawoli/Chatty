#include <bits/stdc++.h>
using namespace std;
int n, m, x1, x2, r, rrk, a[109];
int main ()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n*m; i++)
    {
        cin >> a[i];
    }
    r = a[0];
    sort(a,a+n*m,greater<int>());
    for (int i = 0; i < n*m; i++)
    {
        if (a[i] == r)
        {
            rrk = i;
            break;
        }
    }
    x1 = rrk/n, x2 = rrk%n;
    if (x1&1) x2 = n-x2;
    else ++x2;
    cout << ++x1 << " " << x2 << endl;
    return 0;
}
