#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200009], s[200009], f[200009];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            s[i] = s[i - 1];
            if(a[i] == a[i - 1])
                s[i] += a[i];
        }
        for(int i = 2; i <= n; i++) {
            f[i] = s[i] - s[1];
            for(int j = 1; j < i; j++) {
                f[i] = max(f[i], f[j] + s[i] - s[j + 1] + ((a[i] == a[j]) ? a[i] : 0));
            }
            printf("%d ", f[i]);
        }
        printf("%d\n", f[n]);
    }
    return 0;
}