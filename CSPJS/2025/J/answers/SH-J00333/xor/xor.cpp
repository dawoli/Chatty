#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010];
bool check(int m)
{
    int curX = a[1], left = m;
    for (int i = 2; i <= n; i ++)
    {
        if (curX == k)
        {
            left --;
            curX = a[i];
        }
        else
        {
            curX ^= a[i];
        }
    }
    if (curX == k)
    {
        left --;
    }
    if (!left)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i --)
    {
        if (check(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}