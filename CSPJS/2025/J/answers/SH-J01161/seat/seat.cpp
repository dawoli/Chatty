#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    long long n, m, xm;
    cin >> n >> m;
    long long a[n * m];
    for (int i = 0; i < n * m; i ++)
    {
        cin >> a[i];
        if (i == 0) xm = a[i];
    }
    sort(a, a + n * m);
    if (xm == a[n * m - 1]){
        cout << "1 1";
        return 0;
    }
    long long x = 1, y = 1;
    for (int i = n * m - 2; i >= 0; i --)
    {
        if (y % 2 != 0) x ++;
        if (y % 2 == 0) x --;
        if (x > n || x < 1)
        {
            if (y % 2 != 0) x --;
            if (y % 2 == 0) x ++;
            y ++;
        }
        if (a[i] == xm)
        {
            cout << y << " " << x;
            return 0;
        }
        //cout << a[i] << " " << y << " " << x << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
