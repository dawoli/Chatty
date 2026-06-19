#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500009], f[500009], got[2000009];
bool vst[2000009];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &m);
    vst[0] = true;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] ^= a[i - 1];
        f[i] = f[i - 1];
        if(vst[a[i] ^ m])
            f[i] = max(f[i], got[a[i] ^ m] + 1);
        vst[a[i]] = true;
        got[a[i]] = max(got[a[i]], f[i]);
    }
    printf("%d\n", f[n]);
    return 0;
}