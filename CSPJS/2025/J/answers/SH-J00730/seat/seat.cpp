#include <bits/stdc++.h>
using namespace std;
int n, m, currow, curcol;
int a[109], id[109], rnk[109];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n * m; i++) {
        scanf("%d", a + i);
        id[i] = i;
    }
    sort(id + 1, id + n * m + 1, [](const int& x, const int& y) {
        return a[x] > a[y];
    });
    for(int i = 1; i <= n * m; i++) {
        rnk[id[i]] = i;
    }
    curcol = (rnk[1] - 1) / n + 1;
    currow = (rnk[1] - 1) % n + 1;
    if(curcol % 2 == 0)
        currow = n - currow + 1;
    printf("%d %d\n", curcol, currow);
    return 0;
}