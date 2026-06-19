#include <cstdio>
using namespace std;

char s[1000005];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    int cnt[10] = {};
    for (int x = 0; ; x++) {
        int i = s[x];
        if (i == 0) break;
        for (int number = 9; number >= 0; number--) {
            if (i == number+'0') cnt[number]++;
        }
    }
    for (int number = 9; number >= 0; number--) {
        for (int i = 0; i < cnt[number]; i++) printf("%d", number);
    }
    return 0;
}
