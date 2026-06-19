#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int id, v;
};
bool cmp(Node x, Node y) { return x.v > y.v; }
Node a[105];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n * m, cmp);

    for (int i = 1; i <= n * m; i++) {
        if (a[i].id == 1) {
            int tmp = ceil(i / (1.0 * n));
            int tmp1;
            if (tmp % 2 == 0) tmp1 = n - (i - 1) % n;
            else tmp1 = (i - 1) % n + 1;
            cout << tmp << " " << tmp1 << "\n";
            return 0;
        }
    }

    return 0;
}
