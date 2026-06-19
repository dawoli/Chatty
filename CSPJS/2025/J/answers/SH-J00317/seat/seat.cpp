#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 108;
int n, m, a[MAX], tar;
bool cmp(int a, int b) {return a > b;}

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    tar = a[1];
    sort(a + 1, a + n * m + 1, cmp);

    int row, col;
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == tar)
        {
            col = ceil(i / (n * 1.0));
            int rmrow = i - (col - 1) * n;
            if (col % 2 == 1) row = rmrow;
            else row = n - rmrow + 1;
            break;
        }
    }
    cout << col << " " << row;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
