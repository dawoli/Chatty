#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1000009], out[1000009];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        if(isdigit(s[i]))
            out[++m] = s[i];
    }
    sort(out + 1, out + m + 1, [](const char& a, const char& b) {
        return a > b;
    });
    printf("%s\n", out + 1);
    return 0;
}